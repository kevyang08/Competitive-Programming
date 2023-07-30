#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(10001);
bool vis[10001];
int ans = 0;
int dfs(int i) {
    vis[i] = true;
    int m1 = 0, m2 = 0;
    for (int j : adj[i]) {
        if (vis[j]) continue;
        int res = dfs(j);
        if (res > m1) {
            int temp = m1;
            m1 = res;
            res = temp;
        }
        if (res > m2) m2 = res;
    }
    ans = max(ans, m1 + m2);
    return m1 + 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}
