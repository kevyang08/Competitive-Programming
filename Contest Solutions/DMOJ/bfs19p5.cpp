#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, q, u, v, sz[100005], usz[100005], p[100005], up[18][100005], tin[100005], tout[100005], cur = 0;
ll dp[100005], udp[100005];
vector<int> adj[100005];
int dist(int a, int b) {
    int res = 0;
    for (int k = 17; k >= 0; k--)
        if (up[k][a] && (tin[up[k][a]] > tin[b] || tout[up[k][a]] < tout[b])) {
            res += (1 << k);
            a = up[k][a];
        }
    for (int k = 17; k >= 0; k--)
        if (up[k][b] && (tin[up[k][b]] > tin[a] || tout[up[k][b]] < tout[a])) {
            res += (1 << k);
            b = up[k][b];
        }
    return res;
}
void dfs1(int i, int pa) {
    tin[i] = ++cur;
    p[i] = pa;
    up[0][i] = pa;
    for (int k = 1; k < 18; k++) up[k][i] = up[k - 1][up[k - 1][i]];
    for (auto &j : adj[i]) {
        if (j == pa) continue;
        dfs1(j, i);
        sz[i] += sz[j];
        dp[i] += dp[j] + sz[j];
    }
    ++sz[i];
    ++dp[i];
    tout[i] = ++cur;
}
void dfs2(int i, ll pdp, int psz) {
    for (auto &j : adj[i]) {
        if (j == p[i]) continue;
        dfs2(j, dp[i] + pdp + psz - dp[j] - sz[j], sz[i] + psz - sz[j]);
    }
    udp[i] = pdp + psz;
    usz[i] = psz;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    while (q--) {
        cin >> u >> v;
        ll d = dist(u, v);
        // ll ans = (up[p[u]] + dp[p[u]] - dp[u]) * (dp[v] - dp[u]) + (up[p[v]] + dp[p[v]] - dp[v] - sz[v]) * (dp[u] - dp[v]);
        ll ans = (udp[p[u]] + dp[p[u]] - dp[u] - dp[v] - sz[v] * d) * (sz[v] - sz[u]) + (sz[p[u]] + usz[p[u]] - sz[u] - sz[v]) * (dp[v] - dp[u])
               + (udp[p[v]] + dp[p[v]] - dp[v] - dp[u] - sz[u] * d) * (sz[u] - sz[v]) + (sz[p[v]] + usz[p[v]] - sz[v] - sz[u]) * (dp[u] - dp[v]);
        // cout << ans << " DEBUG\n"; // debug
        cout << (ans < 0 ? -1 : (ans > 0)) << '\n';
    }
    return 0;
}