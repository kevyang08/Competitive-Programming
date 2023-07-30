#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100001);
bool vis[100001];
int mx[100001];
void dfs(int i) {
    vis[i] = true;
    int m = 0;
    for (int j : adj[i]) {
        if (!vis[j]) dfs(j);
        if (mx[j] > m) m = mx[j];
    }
    mx[i] = m + 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
        ans = max(ans, mx[i]);
    }
    cout << ans - 1 << "\n";
    return 0;
}
