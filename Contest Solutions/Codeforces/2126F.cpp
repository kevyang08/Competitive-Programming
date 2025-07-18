#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, q, u, v, c, x, a[200001], p[200001], pc[200001];
vector<pair<int, int>> adj[200001];
map<int, ll> mp[200001];
ll ans;
void dfs(int i, int pa, int ppc) {
    p[i] = pa;
    pc[i] = ppc;
    for (auto &[j, cc] : adj[i]) {
        if (j == pa) continue;
        dfs(j, i, cc);
        if (a[j] != a[i]) ans += cc;
        mp[i][a[j]] += cc;
    }
}
void solve() {
    cin >> n >> q;
    ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) mp[i].clear(), adj[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    dfs(1, 0, 0);
    while (q--) {
        cin >> v >> x;
        if (v != 1) {
            if (a[p[v]] != a[v]) ans -= pc[v];
            if (a[p[v]] != x) ans += pc[v];
            mp[p[v]][a[v]] -= pc[v];
            mp[p[v]][x] += pc[v];
        }
        ans += mp[v][a[v]];
        ans -= mp[v][x];
        a[v] = x;
        cout << ans << "\n";
    }
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