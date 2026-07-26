#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, u, v, a, b, deg[200005], r;
vector<int> adj[200005];
deque<int> dq;
bool dfs(int i, int p) {
    if (i == b) {
        dq.push_back(i);
        return true;
    }
    for (int j : adj[i]) {
        if (j == p) continue;
        if (dfs(j, i)) {
            dq.push_back(i);
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) deg[i] = 0, adj[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) q.push(i);
    a = b = -1;
    while (q.size() > 2) { // not a line basically
        u = q.front(), q.pop();
        v = q.front(), q.pop();
        n -= 2;
        cout << "? " << u << " " << v << endl;
        cin >> r;
        if (r) {
            a = u, b = v;
            break;
        }
        for (int j : adj[u]) {
            --deg[j];
            if (deg[j] == 1) q.push(j);
        }
        for (int j : adj[v]) {
            --deg[j];
            if (deg[j] == 1) q.push(j);
        }
    }
    // if (q.size() == 1 && a == -1) { // should not be possible
    //     cout << "! " << q.front() << endl;
    //     return;
    // }
    if (a == -1) {
        a = q.front(), q.pop();
        b = q.front(), q.pop();
    }
    dfs(a, 0);
    a = b = -1;
    while (dq.size() > 2) {
        u = dq.front(); dq.pop_front();
        v = dq.front(); dq.pop_front();
        cout << "? " << u << " " << v << endl;
        cin >> r;
        if (r) {
            a = u, b = v;
            break;
        }
    }
    if (a == -1) a = dq.front(), b = dq.back();
    cout << "? " << a << " " << a << endl;
    cin >> r;
    if (r) cout << "! " << a << endl;
    else cout << "! " << b << endl;
    dq.clear();
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