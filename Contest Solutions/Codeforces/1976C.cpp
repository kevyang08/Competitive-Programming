#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[200005], b[200005], dp[2][200005];
bool thing[200005], snub[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int cnta = 0, cntb = 0;
        long long ans = 0;
        for (int i = 1; i <= n + m + 1; i++) cin >> a[i];
        for (int i = 1; i <= n + m + 1; i++) cin >> b[i];
        for (int i = 1; i <= n + m; i++) {
            if (a[i] > b[i] && cnta < n || cntb >= m) {
                if (cntb >= m && a[i] < b[i]) snub[i] = true;
                else snub[i] = false;
                cnta++;
                ans += a[i];
                thing[i] = true;
            }
            else {
                if (cnta >= n && a[i] > b[i]) snub[i] = true;
                else snub[i] = false;
                cntb++;
                ans += b[i];
                thing[i] = false;
            }
        }
        snub[n + m + 1] = false;
        dp[0][n + m + 1] = dp[1][n + m + 1] = n + m + 1;
        for (int i = n + m; i > 0; i--) {
            if (snub[i + 1]) dp[!thing[i + 1]][i] = i + 1;
            else dp[!thing[i + 1]][i] = dp[!thing[i + 1]][i + 1];
            dp[thing[i + 1]][i] = dp[thing[i + 1]][i + 1];
        }
        for (int i = 1; i <= n + m; i++) {
            if (thing[i]) cout << ans - a[i] + a[dp[thing[i]][i]] - b[dp[thing[i]][i]] + b[n + m + 1] << " ";
            else cout << ans - b[i] + b[dp[thing[i]][i]] - a[dp[thing[i]][i]] + a[n + m + 1] << " ";
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
