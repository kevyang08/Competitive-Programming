#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a, dp[3][300001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    dp[1][0] = dp[2][0] = -INF;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            dp[0][i] = dp[0][i - 1] + (dp[0][i - 1] == a ? 0 : dp[0][i - 1] < a ? 1 : -1);
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[2][i] = max(dp[1][i - 1] + (dp[1][i - 1] == a ? 0 : dp[1][i - 1] < a ? 1 : -1), dp[2][i - 1] + (dp[2][i - 1] == a ? 0 : dp[2][i - 1] < a ? 1 : -1));
        }
        cout << max(dp[2][n], dp[1][n]) << "\n";
    }
    return 0;
}