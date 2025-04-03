#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, m, u, v, c[500001], deg[500001];
vector<pair<int, int>> adj[500001];
bool vis[500001], del[500001];
void dfs(int i) {
    while (!adj[i].empty()) {
        auto [j, idx] = adj[i].back(); adj[i].pop_back();
        if (del[idx]) continue;
        del[idx] = true;
        dfs(j);
    }
    cout << i << " ";
}
void dfs1(int i) {
    vis[i] = true;
    for (auto &[j, idx] : adj[i]) {
        if (c[idx] || vis[j]) continue;
        dfs1(j);
        if (deg[j]) {
            --m;
            deg[j] ^= 1, deg[i] ^= 1;
            del[idx] = true;
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        fill(del, del + m + 1, 0);
        fill(deg, deg + n + 1, 0);
        for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = false;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> c[i];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            deg[u] ^= 1, deg[v] ^= 1;
        }
        for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
        bool thing = true;
        for (int i = 1; i <= n; i++) thing &= !deg[i];
        if (!thing) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n" << m << "\n";
        dfs(1);
        cout << "\n";
    }
    return 0;
}