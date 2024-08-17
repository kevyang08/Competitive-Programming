#include <bits/stdc++.h>
using namespace std;

int n, q, u, v, k, tin[200001], tout[200001], t = 0, up[18][200001];
vector<int> adj[200001];
void dfs(int i, int p) {
    tin[i] = ++t;
    up[0][i] = p;
    for (int j = 1; j < 18; j++) up[j][i] = up[j - 1][up[j - 1][i]];
    for (auto &j : adj[i]) if (j != p) dfs(j, i);
    tout[i] = ++t;
}
int lca(int u, int v) {
    if (tin[u] <= tin[v] && tout[v] <= tout[u]) return u;
    if (tin[v] <= tin[u] && tout[u] <= tout[v]) return v;
    for (int i = 17; i >= 0; i--) if (!(tin[up[i][v]] <= tin[u] && tout[u] <= tout[up[i][v]])) v = up[i][v];
    return up[0][v];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    dfs(1, 0);
    tout[0] = ++t;
    while (q--) {
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++) cin >> v[i];
        if (k == 1) {
            cout << "YES\n";
            continue;
        }
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
            return tin[a] < tin[b];
        });
        int r = k - 1;
        while (r && lca(v[r], v[r - 1]) == v[r - 1]) --r;
        if (r == 0) {
            cout << "YES\n";
            continue;
        }
        int l = r - 1, res = lca(v[l], v[r]);
        while (l && lca(v[l], v[l - 1]) == v[l - 1] && lca(v[l], v[r]) != v[l] && lca(res, v[l]) == res) --l;
        cout << (l == 0 && lca(res, v[l]) == res ? "YES\n" : "NO\n");
    }
    return 0;
}