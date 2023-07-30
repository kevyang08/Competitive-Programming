#include <bits/stdc++.h>
using namespace std;

double ans = 0, dp[3000][3000];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        double p;
        cin >> p;
        dp[i][0] = dp[i - 1][0] * (1 - p);
        for (int j = 1; j <= i; j++) dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
    }
    for (int i = n/2 + 1; i <= n; i++) ans += dp[n][i];
    cout << setprecision(9) << ans;
}
