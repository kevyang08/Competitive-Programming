#include <bits/stdc++.h>
using namespace std;

int n, d, a, b, c, x, y, t = 0, px = 1, py = 1, h[100001], tin[100001], st[18][200000];
long long d1 = 0, d2 = 0;
vector<pair<int, int>> adj[100001];
void dfs(int i, int p, int l) {
    h[i] = h[p] + l;
    tin[i] = t;
    st[0][t++] = h[i];
    for (pair j : adj[i]) {
        if (j.first == p) continue;
        dfs(j.first, i, j.second);
        st[0][t++] = h[i];
    }
}
int lca(int i, int j) {
    int l = min(tin[i], tin[j]), r = max(tin[i], tin[j]) + 1, k = 31 - __builtin_clz(r - l);
    return h[i] + h[j] - 2 * min(st[k][l], st[k][r - (1 << k)]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(1, 0, 0);
    for (int i = 1; i < 31 - __builtin_clz(2 * n) + 1; i++) {
        for (int j = 0; j < 2 * n - (1 << (i - 1)); j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (d--) {
        cin >> x >> y;
        long long temp = d1;
        d1 = lca(x, y) + min(d1 + lca(px, y), d2 + lca(py, y));
        d2 = lca(x, y) + min(temp + lca(px, x), d2 + lca(py, x));
        px = x; py = y;
    }
    cout << min(d1, d2) << "\n";
    return 0;
}
