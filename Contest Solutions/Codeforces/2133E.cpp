#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int t, n, u, v, cnt[200005], deg[200005];
vector<int> adj[200005];
vector<pair<int, int>> ans;
void dfs(int i, int p) {
    cnt[i] = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        cnt[i] += cnt[j];
    }
    if (cnt[i] > 3) {
        --deg[p]; deg[i] = 0;
        ans.push_back({2, i});
        cnt[i] = 0;
    }
}
void dfs2(int i) {
    deg[i] = 0;
    ans.push_back({1, i});
    for (int j : adj[i]) if (deg[j]) dfs2(j);
}
void solve() {
    ans.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), deg[i] = 0;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) if (!deg[i]) ans.push_back({1, i});
    for (int i = 1; i <= n; i++) if (deg[i] == 1) dfs2(i);
    cout << ans.size() << "\n";
    for (auto &[a, b] : ans) cout << a << " " << b << "\n";
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