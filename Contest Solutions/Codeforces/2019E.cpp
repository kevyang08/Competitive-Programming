#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, u, v, cd[500005], cl[500005];
vector<int> adj[500005];
int dfs(int i, int p, int d) {
    ++cd[d];
    int mx = d;
    for (int j : adj[i]) {
        if (j == p) continue;
        mx = max(mx, dfs(j, i, d + 1));
    }
    ++cl[mx];
    return mx;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        cd[n + 1] = 0;
        for (int i = 1; i <= n; i++) cd[i] = cl[i] = 0, adj[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0, 1);
        int mn = n;
        for (int i = 1; i <= n; i++) cl[i] += cl[i - 1];
        for (int i = n; i > 0; i--) cd[i] += cd[i + 1], mn = min(mn, cd[i + 1] + cl[i - 1]);
        cout << mn << "\n";
    }
    return 0;
}