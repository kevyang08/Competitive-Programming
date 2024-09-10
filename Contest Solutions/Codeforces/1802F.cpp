#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, m, p, a, b, s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> p;
        vector<int> w(n + 1);
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<map<int, ll>> dist(n + 1);
        vector<map<int, int>> cnt(n + 1);
        for (int i = 1; i <= n; i++) cin >> w[i];
        while (m--) {
            cin >> a >> b >> s;
            adj[a].push_back({b, s});
            adj[b].push_back({b, s});
        }
        priority_queue<pair<tuple<ll, int, int>, int>, vector<pair<tuple<ll, int, int>, int>>, greater<pair<tuple<ll, int, int>, int>>> pq;
        dist[1][w[1]] = 0;
        cnt[1][0] = p;
        pq.push({{0, 0, -p}, 1});
        while (!pq.empty()) {
            auto [fi, i] = pq.top(); pq.pop();
            auto [sm, mx, c] = fi;
            c = cnt[i][-mx];

            // cout << i << " " << sm << " " << -mx << " " << c << " bruh\n";

            mx = max(-mx, w[i]);
            for (auto &[j, v] : adj[i]) {
                int tmp = (c >= v ? 0 : (v - c - 1)/mx + 1);
                if (dist[j].find(mx) != dist[j].end() && (dist[j][mx] < sm + tmp || dist[j][mx] == sm + tmp && cnt[j][mx] >= c + tmp * mx - v)) continue;
                dist[j][mx] = sm + tmp;
                cnt[j][mx] = c + tmp * mx - v;
                pq.push({{sm + tmp, -mx, -cnt[j][mx]}, j});
            }
        }
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for (auto &[k, v] : dist[n]) ans = min(ans, v);
        cout << (ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans) << "\n";
    }
    return 0;
}