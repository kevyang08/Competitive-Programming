#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, u, v, l, dp[20][1 << 20];
vector<pair<int, int>> adj[20];
int tsp(int mask, int idx) {
    if (idx == n - 1) return 0;
    if (dp[idx][mask] != -1) return dp[idx][mask];
    dp[idx][mask] = -INF;
    for (auto &[j, d] : adj[idx]) {
        if (mask & (1 << j)) continue;
        dp[idx][mask] = max(dp[idx][mask], tsp(mask | (1 << j), j) + d);
    }
    return dp[idx][mask];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
    }
    cout << tsp(1, 0) << "\n";
    return 0;
}