#include <bits/stdc++.h>
using namespace std;

int t, n, x, a, dp[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int ans = 1;
        for (int j = 1; j * j <= x; j++) dp[j] = dp[x/j] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (x%a) continue;
            for (int j = 2; j * j <= x; j++) if (dp[j] && j%a == 0) ++dp[j/a];
            for (int j = (int)sqrt(x); j > 1; j--) if (dp[x/j] && x/j%a == 0) ++dp[x/j/a];
            if (dp[1]) {
                ++ans;
                for (int j = 1; j * j <= x; j++) dp[j] = dp[x/j] = 0;
            }
            ++dp[x/a];
        }
        cout << ans << "\n";
    }
    return 0;
}