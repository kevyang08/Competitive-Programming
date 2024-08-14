#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, sz[100001], op, x, pa[100001];
long long ans[100001];
set<pair<int, int>> st[100001];
vector<int> adj[100001];
void dfs(int i, int p) {
    sz[i] = 1;
    pa[i] = p;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        st[i].insert({-sz[j], j});
        ans[i] += ans[j];
        sz[i] += sz[j];
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> ans[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    while (m--) {
        cin >> op >> x;
        if (op == 1) cout << ans[x] << "\n";
        else {
            if (st[x].empty()) continue;
            int s = st[x].begin() -> second;
            st[x].erase(st[x].begin());
            st[pa[x]].erase({-sz[x], x});
            int ts = sz[x] - sz[s];
            long long ta = ans[x] - ans[s];
            sz[s] = sz[x];
            sz[x] = ts;
            ans[s] = ans[x];
            ans[x] = ta;
            pa[s] = pa[x];
            pa[x] = s;
            st[s].insert({-sz[x], x});
            st[pa[s]].insert({-sz[s], s});
        }
    }
    return 0;
}