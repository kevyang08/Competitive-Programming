#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], dp[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int mn = 0;
        fill(dp, dp + n + 1, 0x3f3f3f3f);
        for (int i = 1; i <= n; i++) {
            if (dp[i - 1] != 0x3f3f3f3f) mn = min(dp[i - 1], mn);
            cin >> a[i];
            if (i + a[i] <= n) dp[i + a[i]] = min(mn, dp[i + a[i]]);
            mn++;
        }
        if (dp[n] != 0x3f3f3f3f) mn = min(dp[n], mn);
        cout << mn << "\n";
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
