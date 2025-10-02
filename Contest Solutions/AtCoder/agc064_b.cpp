#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, m, a, b;
char c;
vector<array<int, 4>> ed;
vector<int> used, vis, ans, id;
vector<vector<tuple<int, int, int>>> adj;
string s;
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int x, int y) {
    if (id[x = find(x)] > id[y = find(y)]) swap(x, y);
    id[x] += id[y];
    id[y] = x;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    id.resize(n, -1);
    adj.resize(n);
    vis.resize(n);
    used.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        --a, --b;
        ed.push_back({a, b, c == 'R', i});
        adj[a].push_back({b, c == 'R', i});
        adj[b].push_back({a, c == 'R', i});
    }
    cin >> s;
    queue<int> q;
    for (auto [a, b, c, i] : ed) {
        if (s[a] != s[b] || c != (s[a] == 'R') || find(a) == find(b)) continue;
        join(a, b);
        used[i] = 1;
        ans.push_back(i + 1);
        if (!vis[a]) q.push(a), vis[a] = 1;
        if (!vis[b]) q.push(b), vis[b] = 1;;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, c, i] : adj[u]) {
            if (vis[v] || used[i] || find(u) == find(v) || (s[v] == 'R') != c) continue;
            join(u, v);
            used[i] = 1;
            ans.push_back(i + 1);
            q.push(v);
            vis[v] = 1;
        }
    }
    for (int i = 0; i < n; i++) 
        if (!vis[i]) {
            cout << "No\n";
            return 0;
        }
    for (auto [a, b, c, i] : ed) {
        if (find(a) == find(b)) continue;
        join(a, b);
        ans.push_back(i + 1);
    }
    cout << "Yes\n";
    for (int &i : ans) cout << i << ' ';
    cout << "\n";
    return 0;
}