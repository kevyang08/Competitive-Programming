#include <bits/stdc++.h>
using namespace std;

// terrible variable names

int t, n, k, x, u, v, dist[200001];
vector<int> adj[200001];
bool thing[200001], vis[200001];
void dfs1(int i, int p) {
    if (thing[i]) dist[i] = 0;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs1(j, i);
        dist[i] = min(dist[i], dist[j] + 1);
    }
}
void dfs2(int i, int p, int d) {
    vis[i] = true;
    for (int j : adj[i]) {
        if (j == p || d + 1 >= dist[j]) continue;
        dfs2(j, i, d + 1);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            thing[i] = vis[i] = false;
            dist[i] = 0x3f3f3f3f;
            adj[i].clear();
        }
        for (int i = 1; i <= k; i++) {
            cin >> x;
            thing[x] = true;
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(1, 0);
        dfs2(1, 0, 0);
        int thing = false;
        for (int i = 2; i <= n; i++) if (adj[i].size() < 2 && vis[i]) thing = true;
        cout << (thing ? "YES\n" : "NO\n");
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
