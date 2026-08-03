#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, deg[200005], d[200005], u, v, c, mx[200005];
vector<int> adj[200005];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), deg[i] = 0, d[i] = 0, mx[i] = 0;
    ll ans = 0;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) {
        ++cnt;
        d[i] = 1;
        q.push(i);
    }
    while (!q.empty()) {
        c = q.front(); q.pop();
        for (int j : adj[c]) {
            --deg[j];
            d[j] ^= d[c];
            if (d[c]) mx[j] = max(mx[j], mx[c] + 1);
            else mx[j] = max(mx[j], mx[c] - 1);
            if (deg[j] == 1) q.push(j);
        }
        ans += d[c];
    }
    if (cnt & 1) ans -= mx[c] + 1;
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