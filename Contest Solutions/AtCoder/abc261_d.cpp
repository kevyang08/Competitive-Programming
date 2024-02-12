#include <bits/stdc++.h>
using namespace std;

int n, m, x[5001], c, y[5001];
long long mx, dp[5001][5001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> c >> y[c];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = mx;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + x[i] + y[j];
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << "\n";
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
