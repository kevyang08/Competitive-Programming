#include <bits/stdc++.h>
using namespace std;

int t, n, k, p, m, e;
vector<int> adj[200001];
long long c[200001], dp[200001];
bool vis[200001];
void dfs(int i) {
    vis[i] = true;
    dp[i] = (adj[i].size() ? 0 : c[i]);
    for (int j : adj[i]) {
        if (!vis[j]) dfs(j);
        dp[i] += dp[j];
    }
    dp[i] = min(dp[i], c[i]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = false;
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= k; i++) {
            cin >> p;
            c[p] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> m;
            while (m--) {
                cin >> e;
                adj[i].push_back(e);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
            cout << dp[i] << (i == n ? "\n" : " ");
        }
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