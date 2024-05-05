#include <bits/stdc++.h>
using namespace std;

int t, n, k, u, v, sz[100005], cnt;
vector<int> adj[100005];
void dfs(int i, int p, int m) {
    sz[i] = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i, m);
        if (sz[j] >= m && cnt < k) cnt++;
        else sz[i] += sz[j];
    }
}
bool check(int m) {
    cnt = 0;
    dfs(1, 0, m);
    return sz[1] >= m && cnt == k;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int l = 1, r = n/(k + 1);
        while (l < r) {
            int m = (l + r + 1)/2;
            if (check(m)) l = m;
            else r = m - 1;
        }
        cout << l << "\n";
    }
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
