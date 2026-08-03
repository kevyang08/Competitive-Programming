#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

/*
for each node u, get len to every other node v st u < v
- no need for lca, just do a dfs from each node
for each ordered node pair (u, v):
- get dist cd (len - 1)
- add num of paths with length d - cd that pass through v
- let e be the last edge on the path u -> ... -> v
    - subtract num of paths with length d - cd that pass through e
divide ans by 3

since vertices matter, we want to recount all paths of length d:
- for all ordered pairs (u, v) st u < v, if len(u, v) == d, ans += d - 3

post submission notes:
- adj matrix dfs is O(n^2), don't do it
- math above may be wrong; for correct math, see code
*/

/*
cnt[k][i] is the num of paths of length k that pass through node i
ecnt[k][i] is the num of paths of length k that pass through edge (p[i], i)
prv[i][j] is the previous node on the path from i to j
*/
int t, n, d, p[2005], u, v, len[2005][2005], cnt[2005][2005], ecnt[2005][2005], prv[2005][2005];
vector<int> adj[2005];
void dfs1(int i, int pa) {
    p[i] = pa;
    for (int &j : adj[i]) if (j != pa) dfs1(j, i);
}
void dfs2(int i, int pa, int lca, int clen, int st) {
    prv[st][i] = pa;
    len[st][i] = clen;
    for (int &j : adj[i]) {
        if (j == pa) continue;
        if (j == p[i]) dfs2(j, i, j, clen + 1, st);
        else dfs2(j, i, lca, clen + 1, st);
    }
    if (st >= i) return;
    if (st == lca) ++cnt[clen][i];
    else if (i == lca) ++cnt[clen][st];
    else {
        ++cnt[clen][st];
        ++cnt[clen][i];
        --cnt[clen][lca];
    }
    --cnt[clen][p[lca]];
    --ecnt[clen][lca];
}
void dfs3(int i, int pa) {
    for (int &j : adj[i]) {
        if (j == pa) continue;
        dfs3(j, i);
        for (int l = 1; l <= n; l++) {
            cnt[l][i] += cnt[l][j];
            ecnt[l][j] += cnt[l][j];
        }
    }
}
void solve() {
    cin >> n >> d;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        for (int j = 1; j <= n; j++) cnt[i][j] = 0, ecnt[i][j] = 0;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) dfs2(i, 0, i, 1, i);
    dfs3(1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (len[i][j] >= d) continue;
            int cd = len[i][j] - 1;
            ans += cnt[d - cd][j];
            if (prv[i][j] == p[j]) ans -= ecnt[d - cd][j];
            else ans -= ecnt[d - cd][prv[i][j]];
        }
    }
    for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) if (len[i][j] == d) ans -= (d - 2) * 2;
    assert(ans%3 == 0);
    ans /= 3;
    for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) if (len[i][j] == d) ans += d - 2;
    cout << ans << "\n";
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