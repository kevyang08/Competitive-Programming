#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, u, v, deg[200001], c[200001], idx;
vector<int> adj[200001];
void dfs(int i, int p, int d, int f) {
    if (i == idx) {
        dfs(adj[i][0], i, 0, 0);
        dfs(adj[i][1], i, 0, 1);
        cout << adj[i][1] << " " << i << "\n";
        return;
    }
    for (int j : adj[i]) {
        if (d == f) cout << j << " " << i << "\n";
        if (j == p) continue;
        dfs(j, i, d ^ 1, f);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) deg[i] = 0, c[i] = 0, adj[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    idx = -1;
    for (int i = 1; i <= n; i++) if (deg[i] == 2) idx = i;
    if (idx == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    dfs(idx, 0, 0, 0);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}