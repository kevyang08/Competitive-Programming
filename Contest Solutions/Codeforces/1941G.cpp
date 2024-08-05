#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, c, d[200005], s, e, bruh[200005];
vector<pair<int, int>> adj[200005];
bool inq[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        queue<int> q, tq;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            d[i] = 0x3f3f3f3f;
        }
        while (m--) {
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
            bruh[c] = 0;
        }
        cin >> s >> e;
        for (auto &[a, b] : adj[s]) bruh[b] = 1;
        tq.push(s);
        d[s] = 0;
        for (int i = 1; i <= n; i++) {
            while (!tq.empty()) q.push(tq.front()), inq[tq.front()] = false, tq.pop();
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (d[u] < i && u != s) continue;
                for (auto &[a, b] : adj[u]) {
                    if (!bruh[b]) bruh[b] = i + 1;
                    if (d[a] <= i) continue;
                    if (bruh[b] == i) {
                        d[a] = i;
                        q.push(a);
                    }
                    else {
                        if (inq[a]) continue;
                        tq.push(a);
                        d[a] = i + 1;
                        inq[a] = true;
                    }
                }
            }
        }
        cout << d[e] << "\n";
    }
    return 0;
}