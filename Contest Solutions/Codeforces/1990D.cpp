#include <bits/stdc++.h>
using namespace std;

int t, n, a, dp[3][200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    dp[1][0] = dp[2][0] = 0x3f3f3f3f;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            dp[1][i] = dp[2][i] = 0x3f3f3f3f;
            cin >> a;
            dp[0][i] = min(dp[1][i - 1] + (a > 2), min(dp[0][i - 1], dp[2][i - 1]) + (a > 0));
            if (!a) continue;
            else if (a < 3) dp[1][i] = min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1])) + 1;
            else if (a < 5) {
                dp[1][i] = dp[2][i - 1] + 1;
                dp[2][i] = dp[1][i - 1] + 1;
            }
        }
        cout << min(dp[0][n], min(dp[1][n], dp[2][n])) << "\n";
    }
    return 0;
}