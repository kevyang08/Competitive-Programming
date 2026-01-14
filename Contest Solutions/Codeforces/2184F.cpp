#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, u, v, dp[3][200005];
vector<int> adj[200005];
void dfs(int i, int p) {
    vector<int> tmp(3);
    bool first = true;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        if (first) {
            first = false;
            for (int k = 0; k < 3; k++) dp[k][i] = dp[k][j];
            continue;
        }
        for (int k = 0; k < 3; k++) {
            tmp[k] = dp[k][i];
            dp[k][i] = 0;
        }
        for (int x = 0; x < 3; x++) {
            if (!dp[x][j]) continue;
            for (int k = 0; k < 3; k++) dp[(k + x)%3][i] |= tmp[k];
        }
    }
    dp[1][i] = 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), dp[0][i] = dp[2][i] = 0;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[0][1] ? "YES\n" : "NO\n");
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