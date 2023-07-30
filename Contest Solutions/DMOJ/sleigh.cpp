#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj(100001);
bool vis[100001];
int ans = 0;
int dfs(int i) {
    vis[i] = true;
    int m = 0;
    for (pair p : adj[i]) {
        if (vis[p.first]) continue;
        ans += p.second;
        int res = dfs(p.first) + p.second;
        if (res > m) m = res;
    }
    return m;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int thing = dfs(0);
    cout << 2 * ans - thing << "\n";
    return 0;
}
