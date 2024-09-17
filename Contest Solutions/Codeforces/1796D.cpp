#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, k, x, a[200001];
ll dp[21][200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        ll ans = 0;
        if (x < 0) {
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
                dp[0][i] = 0;
                if (k != n) dp[0][i] = a[i] - x + (k <= n - i ? max(dp[0][i - 1], 0LL) : 0LL);
                ans = max(ans, dp[0][i]);
                for (int j = 1; j <= min(i, k); j++) {
                    if (i > j) dp[j][i] = a[i] - x + max(dp[j][i - 1], 0LL);
                    else {
                        dp[j][i] = a[i] + x + max(dp[j - 1][i - 1], 0LL);
                        // for (int l = 2; l <= j; l++) dp[j][i] = max(dp[j][i], dp[l][i] + max(dp[j - l][i - l], 0LL));
                    }
                    if (k - j <= n - i) ans = max(ans, dp[j][i]);
                }
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
                dp[0][i] = 0;
                if (k != n) dp[0][i] = a[i] - x + max(dp[0][i - 1], 0LL);
                ans = max(ans, dp[0][i]);
                for (int j = 1; j <= min(i, k); j++) {
                    dp[j][i] = a[i] + x + max(dp[j - 1][i - 1], 0LL);
                    // for (int l = 2; l <= j; l++) dp[j][i] = max(dp[j][i], dp[l][i] + max(dp[j - l][i - l], 0LL));
                    ans = max(ans, dp[j][i]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}