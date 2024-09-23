#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, u, v;
bool vis[200001];
char c[200001];
vector<pair<int, int>> adj[200001];
void dfs(int i, int d) {
    for (auto &[j, idx] : adj[i]) if (!vis[j]) {
        vis[j] = true;
        c[idx] = (d ? 'B' : 'R');
        dfs(j, d ^ 1);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        c[i] = 'G';
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) vis[i] = true, dfs(i, 0);
    for (int i = 1; i <= m; i++) cout << c[i];
    cout << "\n";
    return 0;
}