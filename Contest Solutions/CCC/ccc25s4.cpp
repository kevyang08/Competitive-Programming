#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, a, b, c;
vector<ll> dist[200001];
ll ans = INFL;
vector<pair<int, int>> adj[200001];
vector<int> bruh[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        bruh[a].pb(adj[b].size());
        bruh[b].pb(adj[a].size());
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = vector<ll>(adj[i].size());
        fill(dist[i].begin(), dist[i].end(), INFL);
    }
    priority_queue<tuple<ll, int, int>> pq;
    dist[1][0] = 0;
    pq.push({0, 0, 1});
    while (!pq.empty()) {
        auto [d, l, i] = pq.top(); pq.pop();
        d = -d;
        if (i == n) {
            ans = d;
            break;
        }
        for (int k = 0; k < adj[i].size(); k++) {
            auto &[j, v] = adj[i][k];
            int w = bruh[i][k];
            if (d + abs(l - v) < dist[j][w]) {
                dist[j][w] = d + abs(l - v);
                dist[i][k] = min(dist[i][k], dist[j][w]);
                pq.push({-dist[j][w], v, j});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}