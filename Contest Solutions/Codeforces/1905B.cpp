#include <bits/stdc++.h>
using namespace std;
 
int t, n, a, b;
vector<int> adj[100001];
int dfs(int i, int p) {
    if (adj[i].size() == 1 && adj[i][0] == p) return 1;
    int res = 0;
    for (int j : adj[i]) {
        if (j == p) continue;
        res += dfs(j, i);
    }
    if (i == 1 && adj[i].size() == 1) res++;
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = dfs(1, 0);
        cout << ans/2 + ans%2 << "\n";
    }
    return 0;
}
