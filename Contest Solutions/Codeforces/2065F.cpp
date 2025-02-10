#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a[500001], u, v, ans[500001];
vector<int> adj[500001];
void dfs(int i, int p) {
    map<int, int> mp;
    ++mp[a[i]], ++mp[a[p]];
    if (a[i] == a[p]) ans[a[i]] = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        ++mp[a[j]];
        if (mp[a[j]] > 1) ans[a[j]] = 1;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            ans[i] = 0;
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << "\n";
    }
    return 0;
}