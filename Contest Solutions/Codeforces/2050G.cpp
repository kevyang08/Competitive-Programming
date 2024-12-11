#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, u, v, dp[200001], ans;
vector<int> adj[200001];
void dfs(int i, int p) {
    dp[i] = 0;
    int cnt = 0, mx = 0;
    for (int j : adj[i]) {
        if (j == p) continue;
        ++cnt;
        dfs(j, i);
        if (dp[j] > dp[i]) mx = dp[i], dp[i] = dp[j];
        else mx = max(mx, dp[j]);
    }
    ans = max(ans, cnt + (i != 1));
    if (dp[i]) ans = max(ans, dp[i] + cnt - 1 + (i != 1));
    if (mx) ans = max(ans, dp[i] + mx + cnt - 2 + (i != 1));
    dp[i] = max(cnt, dp[i] + cnt - 1);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        cout << ans << "\n";
    }
    return 0;
}