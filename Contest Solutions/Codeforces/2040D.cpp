#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, u, v, a[200001];
set<int> st[2];
vector<int> adj[200001];
void dfs(int i, int p) {
    for (int j : adj[i]) {
        if (j == p) continue;
        int r = (a[i] & 1);
        if (st[r ^ 1].find(a[i] + 1) != st[r ^ 1].end()) {
            a[j] = a[i] + 1;
            st[r ^ 1].erase(a[j]);
        }
        else {
            a[j] = *st[r].lower_bound(a[i] + 4);
            st[r].erase(a[j]);
        }
        dfs(j, i);
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
        st[0].clear(); st[1].clear();
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 2; i <= 2 * n; i++) st[i%2].insert(i);
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        a[1] = 1;
        dfs(1, 0);
        for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? "\n" : " ");
    }
    return 0;
}