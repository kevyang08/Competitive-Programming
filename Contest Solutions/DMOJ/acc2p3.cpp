#include <bits/stdc++.h>
using namespace std;

int n, a, b, w, q, tin[100001], tout[100001], up[18][100001], mx[2][18][100001], t = 0;
vector<pair<int, int>> adj[100001];
void dfs(int i, int p, int w) {
    tin[i] = ++t;
    up[0][i] = p;
    mx[0][0][i] = w;
    for (int j = 1; j < 18; j++) {
        up[j][i] = up[j - 1][up[j - 1][i]];
        mx[0][j][i] = max(mx[0][j - 1][i], mx[0][j - 1][up[j - 1][i]]);
        mx[1][j][i] = (mx[0][j - 1][i] > mx[0][j - 1][up[j - 1][i]] ? max(mx[1][j - 1][i], mx[0][j - 1][up[j - 1][i]]) : max(mx[0][j - 1][i], mx[1][j - 1][up[j - 1][i]]));
    }
    for (auto &[j, l] : adj[i]) {
        if (j == p) continue;
        dfs(j, i, l);
    }
    tout[i] = ++t;
}
int query(int a, int b) {
    if (up[0][a] == b || up[0][b] == a) return -1;
    int mx1 = 0, mx2 = 0;
    auto update = [&](int i, int u) {
        for (int j = 0; j < 2; j++) {
            if (mx[j][i][u] >= mx1) {
                mx2 = mx1;
                mx1 = mx[j][i][u];
            }
            else if (mx[j][i][u] > mx2) mx2 = mx[j][i][u];
        }
    };
    for (int i = 17; i >= 0; i--) 
        if (!(tin[up[i][a]] <= tin[b] && tout[b] <= tout[up[i][a]])) {
            update(i, a);
            a = up[i][a];
            // cout << "a: " << a << " bruh\n";
        }
    if (!(tin[a] <= tin[b] && tout[b] <= tout[a])) update(0, a);
    for (int i = 17; i >= 0; i--) 
        if (!(tin[up[i][b]] <= tin[a] && tout[a] <= tout[up[i][b]])) {
            update(i, b);
            b = up[i][b];
            // cout << "b: " << b << " bruh\n";
        }
    if (!(tin[b] <= tin[a] && tout[a] <= tout[b])) update(0, b);
    return mx2;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dfs(1, 0, 0);
    tin[0] = 0, tout[0] = ++t;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/