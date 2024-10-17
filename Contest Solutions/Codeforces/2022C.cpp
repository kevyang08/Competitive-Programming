#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, dp[3][100001], arr[2][100001];
string s[2];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) cin >> s[i];
        for (int i = 2; i <= n; i++) {
            int c = (s[0][i - 2] == 'A') + (s[1][i - 2] == 'A');
            dp[1][i] = dp[0][i - 2] + (c + (s[0][i - 1] == 'A') > 1);
            dp[2][i] = dp[0][i - 2] + (c + (s[1][i - 1] == 'A') > 1);
            if (i < 3) continue;
            arr[0][i] = (s[0][i - 3] == 'A') + (s[0][i - 2] == 'A') + (s[0][i - 1] == 'A');
            arr[1][i] = (s[1][i - 3] == 'A') + (s[1][i - 2] == 'A') + (s[1][i - 1] == 'A');
            dp[0][i] = (arr[0][i] > 1) + (arr[1][i] > 1) + dp[0][i - 3];
            int d = (s[0][i - 1] == 'A') + (s[1][i - 1] == 'A');
            dp[0][i] = max(dp[0][i], dp[2][i - 1] + (d + (s[0][i - 2] == 'A') > 1));
            dp[0][i] = max(dp[0][i], dp[1][i - 1] + (d + (s[1][i - 2] == 'A') > 1));
            dp[1][i] = max(dp[1][i], dp[1][i - 3] + (arr[0][i] > 1) + (arr[1][i - 1] > 1));
            dp[2][i] = max(dp[2][i], dp[2][i - 3] + (arr[0][i - 1] > 1) + (arr[1][i] > 1));
        }
        cout << dp[0][n] << "\n";
    }
    return 0;
}