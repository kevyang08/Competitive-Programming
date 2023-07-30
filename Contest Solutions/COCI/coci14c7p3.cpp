#include <bits/stdc++.h>
using namespace std;

int n, arr[3][150001], dp[3][150001], ans = 0x3f3f3f3f, bruh[3] = {0, 1, 2};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < 3; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
    do {
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i < n - 1) dp[0][i] = dp[0][i - 1] + arr[bruh[0]][i];
            if (i > 1 && i < n) dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + arr[bruh[1]][i];
            if (i > 2) dp[2][i] = min(dp[1][i - 1], dp[2][i - 1]) + arr[bruh[2]][i];
        }
        ans = min(ans, dp[2][n]);
    } while (next_permutation(bruh, bruh + 3));
    cout << ans << "\n";
}
