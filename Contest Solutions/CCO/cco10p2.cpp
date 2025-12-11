#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, d, u, c[305], m, v, dp[305][605], off = 300;
vector<int> adj[305];
void dfs(int i) {
    if (c[i]) dp[i][off + 1] = adj[i].size();
    else dp[i][off - 1] = adj[i].size();
    for (int j : adj[i]) {
        dfs(j);
        vector<int> tmp(605);
        for (int k = 0; k <= 600; k++) tmp[k] = dp[i][k];
        for (int k = 0; k <= 300; k++) {
            for (int l = 600; l >= k; l--) tmp[l] = min(tmp[l], dp[i][l - k] - 1 + dp[j][k + off]);
            for (int l = 0; l <= 600 - k; l++) tmp[l] = min(tmp[l], dp[i][l + k] - 1 + dp[j][off - k]);
        }
        for (int k = 0; k <= 600; k++) dp[i][k] = tmp[k];
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        fill(dp[i], dp[i] + 601, INF);
        cin >> u >> c[u] >> m;
        while (m--) {
            cin >> v;
            adj[u].push_back(v);
        }
    }
    dfs(0);
    cout << (dp[0][d + off] > n ? -1 : dp[0][d + off]) << "\n";
    return 0;
}