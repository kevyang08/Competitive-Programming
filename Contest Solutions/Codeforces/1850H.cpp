#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
long long d;
vector<pair<int, long long>> adj[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<long long> x(n + 1);
        vector<bool> vis(n + 1);
        bool ans = true;
        for (int i = 1; i <= n; i++) adj[i].clear();
        while (m--) {
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, -d});
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            x[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto &[v, d] : adj[u]) {
                    if (vis[v]) {
                        if (x[u] - x[v] != d) ans = false;
                        continue;
                    }
                    vis[v] = true;
                    x[v] = x[u] - d;
                    q.push(v);
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
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