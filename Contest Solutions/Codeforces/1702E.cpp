#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c[200001];
vector<int> adj[200001];
bool ans;
void dfs(int i, int p, int d) {
    c[i] = d;
    if (adj[i].size() > 2) ans = false;
    for (auto &j : adj[i]) {
        if (j == p) continue;
        if (!c[j]) dfs(j, i, d + 1);
        else if (c[i]%2 == c[j]%2) ans = false;
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
        ans = true;
        for (int i = 1; i <= n; i++) adj[i].clear(), c[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) if (!c[i]) dfs(i, 0, 1);
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}