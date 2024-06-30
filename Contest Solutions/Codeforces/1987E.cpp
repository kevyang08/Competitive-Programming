#include <bits/stdc++.h>
using namespace std;

int t, n, a[5001], p;
long long dp[5001][5001], mn[5001];
vector<int> adj[5001];
long long dfs(int i) {
    long long res = 0, thing = 0;
    if (!adj[i].empty()) mn[i] = 0x3f3f3f3f;
    if (adj[i].empty()) return 0;
    for (int j : adj[i]) {
        res += dfs(j);
        mn[i] = min(mn[i], mn[j] + 1);
        thing += a[j];
        for (int k = 1; k <= n; k++) dp[i][k] += dp[j][k - 1];
    }
    if (a[i] <= thing) dp[i][0] = thing - a[i];
    else {
        // stop taking dp[i][k] when k >= mn[i]
        for (int k = 1; k < mn[i]; k++) {
            long long temp = min(dp[i][k], a[i] - thing);
            dp[i][k] -= temp;
            thing += temp;
            res += temp * k;
        }
        res += mn[i] * (a[i] - thing);
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            adj[i].clear();
            for (int j = 0; j <= n; j++) dp[i][j] = 0;
            mn[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            cin >> p;
            adj[p].push_back(i);
        }
        cout << dfs(1) << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/