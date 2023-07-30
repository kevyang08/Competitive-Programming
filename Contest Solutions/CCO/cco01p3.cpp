#include <bits/stdc++.h>
using namespace std;

int n, k, a, dp[101][101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    dp[1][1] = 1;
    for (int i = 2; i <= 100; i++) {
        dp[i][i] = dp[i][1] = 1;
        for (int j = 2; j < i; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] += dp[i - j][k];
            }
        }
    }
    for (int i = 1; i <= 100; i++) for (int j = 1; j <= i; j++) dp[i][j] += dp[i][j - 1];
    cin >> n;
    while (n--) {
        cin >> k >> a;
        if (a > dp[k][k]) {
            cout << "Too big\n";
            continue;
        }
        cout << "(";
        int s = 0;
        while (s < k) {
            for (int i = 1; i <= k - s; i++) {
                if (dp[k - s][i] >= a && dp[k - s][i - 1] + 1 <= a) {
                    cout << (s == 0 ? "" : ",") << i;
                    a -= dp[k - s][i - 1];
                    s += i;
                    break;
                }
            }
        }
        cout << ")\n";
    }
    return 0;
}
