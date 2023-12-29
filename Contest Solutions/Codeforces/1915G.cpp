#include <bits/stdc++.h>
using namespace std;
 
int t, n, m, u, v, w, s[1001];
long long dist[1001][1001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        memset(dist, 0x3f3f3f3f3f3f3f3f, sizeof(dist));
        vector<pair<int, int>> adj[1001];
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> w;
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }
        for (int i = 1; i <= n; i++) cin >> s[i];
        dist[s[1]][1] = 0;
        priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> pq;
        pq.push({{0, s[1]}, 1});
        while (!pq.empty()) {
            long long d = pq.top().first.first;
            int sm = pq.top().first.second, i = pq.top().second;
            pq.pop();
            for (auto j : adj[i]) {
                int mn = min(sm, s[j.first]);
                if (d + (long long)sm * j.second < dist[mn][j.first]) {
                    dist[mn][j.first] = d + (long long)sm * j.second;
                    pq.push({{dist[mn][j.first], mn}, j.first});
                }
            }
        }
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= 1000; i++) ans = min(ans, dist[i][n]);
        cout << ans << "\n";
    }
    return 0;
}
