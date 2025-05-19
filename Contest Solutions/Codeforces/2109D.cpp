#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, m, l, a, u, v, dist[2][200001];
vector<int> adj[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int s = 0, mn = INT_MAX;
        cin >> n >> m >> l;
        for (int i = 1; i <= n; i++) adj[i].clear(), dist[0][i] = dist[1][i] = INT_MAX;
        while (l--) {
            cin >> a;
            s += a;
            if (a%2) mn = min(mn, a);
        }
        while (m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int, int>> q;
        dist[0][1] = 0;
        q.push({0, 1});
        while (!q.empty()) {
            auto [p, c] = q.front(); q.pop();
            for (int j : adj[c]) {
                if (dist[p][c] + 1 >= dist[p ^ 1][j]) continue;
                dist[p ^ 1][j] = dist[p][c] + 1;
                q.push({p ^ 1, j});
            }
        }
        for (int i = 1; i <= n; i++) cout << (dist[0][i] <= s - (s%2 == 0 ? 0 : mn) || dist[1][i] <= s - (s%2 ? 0 : mn));
        cout << "\n";
    }
    return 0;
}