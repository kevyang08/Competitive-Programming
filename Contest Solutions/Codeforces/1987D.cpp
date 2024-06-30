#include <bits/stdc++.h>
using namespace std;

int t, n, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = 0, m = 0, c = 0;
        vector<int> cnt(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 2));
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (!cnt[a]) ++m;
            ++cnt[a];
        }
        for (int i = 1; i <= n; i++) {
            if (!cnt[i]) {
                for (int j = 0; j <= n + 1; j++) dp[i][j] = dp[i - 1][j];
                continue;
            }
            for (int j = cnt[i]; j <= c; j++) dp[i][j - cnt[i]] = 1 + dp[i - 1][j];
            for (int j = 1; j <= c + 1; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            ++c;
        }
        for (int j = 0; j <= n + 1; j++) mx = max(dp[n][j], mx);
        cout << m - mx << "\n";
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