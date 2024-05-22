#include <bits/stdc++.h>
using namespace std;

int n, a[305][305], dp[5][305][305];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) for (int k = 0; k < 5; k++) dp[k][i][0] = dp[k][0][i] = INT_MIN;
    dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[n - i + 1][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0, x = 0, y = 0; k < 5; k++) {
                dp[k][i][j] = a[i][j] + max(dp[x][i - 1][j], dp[y][i][j - 1]);
                if (dp[x][i - 1][j] > dp[y][i][j - 1]) x++;
                else y++;
            }
        }
    }
    for (int i = 0; i < 5; i++) cout << dp[i][n][n] << "\n";
    return 0;
}
