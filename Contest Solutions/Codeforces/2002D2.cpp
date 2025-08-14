#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, q, a[300001], p[300001], x, y, idx[300001], sz[300001], cnt;
multiset<int> mn[300001], mx[300001];
vector<int> adj[300001];
void dfs(int i) {
    sz[i] = 1;
    for (int j : adj[i]) {
        dfs(j);
        sz[i] += sz[j];
    }
}
void check_pos(int i, int v) {
    if (i == 1 && p[1] != 1) {
        cnt += v;
        return;
    }
    if (sz[i] == 1) return;
    if (*mn[i].begin() <= idx[i] || *mx[i].rbegin() >= idx[i] + sz[i]) cnt += v;

    // // debug
    // if (mn[i].empty()) return;
    // cout << i << " " << *mn[i].begin() << " " << *mx[i].rbegin() << " " << cnt << " bwfowfjaefja\n";
}
void update(int i, int old) {
    if (i == 1) return;
    mn[a[i]].extract(old);
    mx[a[i]].extract(old + sz[i] - 1);
    mn[a[i]].insert(idx[i]);
    mx[a[i]].insert(idx[i] + sz[i] - 1);
}
void solve() {
    cnt = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) adj[i].clear(), mn[i].clear(), mx[i].clear();
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        idx[p[i]] = i;
        if (p[i] == 1) continue;
        mn[a[p[i]]].insert(i);
        mx[a[p[i]]].insert(i + sz[p[i]] - 1);
    }
    for (int i = 1; i <= n; i++) check_pos(i, 1);
    // cout << cnt << " wtf\n"; // debug
    while (q--) {
        cin >> x >> y;
        if (p[x] != 1 && p[x] != a[p[y]]) check_pos(p[x], -1);
        if (p[y] != 1 && p[y] != a[p[x]]) check_pos(p[y], -1);
        check_pos(a[p[x]], -1);
        if (a[p[x]] != a[p[y]]) check_pos(a[p[y]], -1);
        swap(idx[p[x]], idx[p[y]]);
        update(p[x], x);
        update(p[y], y);
        swap(p[x], p[y]);
        if (p[x] != 1 && p[x] != a[p[y]]) check_pos(p[x], 1);
        if (p[y] != 1 && p[y] != a[p[x]]) check_pos(p[y], 1);
        check_pos(a[p[x]], 1);
        if (a[p[x]] != a[p[y]]) check_pos(a[p[y]], 1);
        cout << (cnt ? "NO\n" : "YES\n");
        // cout << cnt << " bruh\n"; // debug
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    a[1] = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}