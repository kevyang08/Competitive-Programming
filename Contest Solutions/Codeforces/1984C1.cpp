#include <bits/stdc++.h>
using namespace std;

int t, n, a;
long long dp[4][200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            dp[0][i] = a + max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = max(max(abs(a + dp[1][i - 1]), abs(a + dp[3][i - 1])), max(abs(a + dp[0][i - 1]), abs(a + dp[2][i - 1])));
            dp[2][i] = a + min(dp[2][i - 1], dp[3][i - 1]);
            dp[3][i] = min(min(abs(a + dp[1][i - 1]), abs(a + dp[3][i - 1])), min(abs(a + dp[0][i - 1]), abs(a + dp[2][i - 1])));
        }
        cout << max(max(dp[0][n], dp[1][n]), max(abs(dp[2][n]), dp[3][n])) << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/