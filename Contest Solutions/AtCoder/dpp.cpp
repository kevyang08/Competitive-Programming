#include <bits/stdc++.h>
using namespace std;

int n, x, y, MOD = 1e9 + 7;
long long dp[100001][2];
vector<int> adj[100001];
void dfs(int i, int p) {
    dp[i][0] = dp[i][1] = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        dp[i][0] = (dp[i][0] * (dp[j][0] + dp[j][1])%MOD)%MOD;
        dp[i][1] = (dp[i][1] * dp[j][0])%MOD;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1])%MOD << "\n";
    return 0;
}
