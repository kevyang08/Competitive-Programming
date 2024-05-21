#include <bits/stdc++.h>
using namespace std;

int t, n, x, c, h;
long long dp[50001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int mx = 0;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> c >> h;
            mx += h;
            for (int j = mx; j >= h; j--) if (dp[j - h] >= c) dp[j] = max(dp[j - h] - c, dp[j]);
            for (int j = 0; j <= mx; j++) if (dp[j] != -1) dp[j] += x;
        }
        int ans = 0;
        for (int i = 1; i < 50001; i++) if (dp[i] != -1) ans = i;
        cout << ans << "\n";
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
