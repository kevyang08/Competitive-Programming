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
- graph must be bipartite
- we cannot have any a, b, c, d such that:
    - a, c are irrelevant
    - a, d are destined
    - b, c are destined
    - b, d are irrelevant
*/

int n, m, type, a, b, c[200005], idx[200005], ind[200005];
map<int, int> adj[200005];
bool flag;
void dfs(int i, int cc) {
    c[i] = cc;
    for (auto &[j, tt] : adj[i]) {
        if (c[j] == -1) dfs(j, cc ^ 1);
        if (c[j] == c[i]) flag = 0;
    }
}
void solve() {
    cin >> n >> m;
    flag = 1;
    int cdx = 0;
    for (int i = 1; i <= n; i++) c[i] = -1, idx[i] = -1, ind[i] = 0, adj[i].clear();
    vector<tuple<int, int, int>> ve;
    while (m--) {
        cin >> type >> a >> b;
        adj[a].emplace(b, type%2);
        adj[b].emplace(a, type%2);
        ve.push_back({type%2, a, b});
    }
    for (int i = 1; i <= n; i++) if (c[i] == -1) dfs(i, 0);
    if (!flag) {
        cout << "NO\n";
        return;
    }
    for (auto &[tt, u, v] : ve) {
        if (c[u] != tt) adj[v].erase(u), ++ind[v];
        else adj[u].erase(v), ++ind[u];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        idx[i] = cdx++;
        for (auto &[j, tt] : adj[i]) {
            --ind[j];
            if (!ind[j]) q.push(j);
        }
    }
    if (cdx < n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        if (c[i] == -1) c[i] = 0;
        cout << (c[i] ? 'R' : 'L') << " " << idx[i] << "\n";
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}