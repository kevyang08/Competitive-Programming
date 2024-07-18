#include <bits/stdc++.h>
using namespace std;

/*
- prefix sums
- bs when g > x for each start
- dp backwards
*/

int t, n, x;
long long a[200005], dp[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        dp[n + 1] = 0;
        for (int i = n; i > 0; i--) {
            dp[i] = 0;
            int l = i, r = n + 1;
            while (l < r) {
                int m = (l + r)/2;
                if (a[m] - a[i - 1] > x) r = m;
                else l = m + 1;
            }
            if (r <= n) dp[i] = 1 + dp[r + 1];
            ans += n - i + 1 - dp[i];
        }
        cout << ans << "\n";
    }
    return 0;
}