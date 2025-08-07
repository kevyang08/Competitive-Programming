#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 1e9 + 7;

int t, n, m, u, v, d[200001], cnt[200001];
vector<int> adj[200001];
ll ans, f[200001];
bool dfs1(int i, int p) {
    int res = 1;
    for (int j : adj[i]) {
        if (j != p) res &= dfs1(j, i);
        // if (c[j] == c[i]) res = 0;
        if (d[j] > 1) ++cnt[i];
    }
    if (cnt[i] > 2) res = 0;
    return res;
}
void dfs2(int i, int p) {
    ans = (ans * f[d[i] - cnt[i]])%M;
    for (int j : adj[i]) if (j != p) dfs2(j, i);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) adj[i].clear(), d[i] = 0, cnt[i] = 0;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++d[u], ++d[v];
    }
    if (n == 2) {
        cout << "2\n";
        return;
    }
    if (m > n - 1 || !dfs1(1, 0)) {
        cout << "0\n";
        return;
    }
    ans = 2;
    for (int i = 1; i <= n; i++) if (d[i] > 1 && cnt[i] > 0) ans = 4;
    dfs2(1, 0);
    cout << ans << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    f[0] = 1;
    for (int i = 1; i <= 200000; i++) f[i] = (f[i - 1] * i)%M;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}