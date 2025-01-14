#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 1e6;

int n, m, a, adj[701][701], dist[2][701], c[701], ways[2][701];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> adj[i][j];
        dist[0][i] = dist[1][i] = INF;
    }
    cin >> m;
    while (m--) {
        cin >> a;
        c[a] = 1;
    }
    priority_queue<tuple<int, int, int>> pq;
    dist[c[1]][1] = 0;
    ways[c[1]][1] = 1;
    pq.push({-dist[c[1]][1], c[1], 1});
    while (!pq.empty()) {
        auto [d, cc, i] = pq.top(); pq.pop();
        d = -d;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int tmp = cc | c[j];
            if (d + adj[i][j] < dist[tmp][j]) {
                dist[tmp][j] = d + adj[i][j];
                ways[tmp][j] = ways[cc][i];
                pq.push({-dist[tmp][j], tmp, j});
            }
            else if (d + adj[i][j] == dist[tmp][j]) ways[tmp][j] = (ways[tmp][j] + ways[cc][i])%M;
        }
    }
    cout << dist[1][n] << " " << ways[1][n] << "\n";
    return 0;
}