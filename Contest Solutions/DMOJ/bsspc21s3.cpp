#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[1000001], dp[1000001], ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        if (i >= k) dp[i] = a[i] - a[i - k];
        if (i >= 2 * k && dp[i - k] > 0) dp[i] += dp[i - k];
        ans = max(ans, dp[i]); 
    }
    cout << ans << "\n";
    return 0;
}
