#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, f[1000001], a, b, scc[1000001], cnt = 0;
long long dp[1000001], sum[1000001];
vector<int> adj[1000001], adjr[1000001];
vector<int> order;
bool vis[1000001];
void dfs1(int i) {
    vis[i] = true;
    for (auto j : adj[i]) if (!vis[j]) dfs1(j);
    order.push_back(i);
}
void dfs2(int i, int c) {
    scc[i] = c;
    sum[scc[i]] += f[i];
    for (int j : adjr[i]) {
        if (!scc[j]) dfs2(j, c);
        else if (scc[j] != scc[i] && dp[scc[j]] != -0x3f3f3f3f) dp[scc[i]] = max(dp[scc[i]], dp[scc[j]] + sum[scc[j]]);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    memset(dp, -0x3f3f3f3f, sizeof(dp));
    cin >> n >> m >> s >> e;
    for (int i = 1; i <= n; i++) cin >> f[i];
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    reverse(order.begin(), order.end());
    for (int i : order) if (!scc[i]) {
        dfs2(i, ++cnt);
        if (scc[i] == scc[s]) dp[scc[i]] = 0;
    }
    cout << dp[scc[e]] + sum[scc[e]] << "\n";
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