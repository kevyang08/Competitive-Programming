#include <bits/stdc++.h>
using namespace std;

int t, n, a[200005], up[200005], down[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = n - 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            down[i] = down[i - 1] + (a[i] >= a[i - 1]);
        }
        // up[n + 1] = up[n];
        // down[n] = 0;
        up[n + 1] = up[n] = 0;
        for (int i = n - 1; i > 0; i--) up[i] = up[i + 1] + (a[i] >= a[i + 1]);
        // down[0] = down[1];
        for (int i = 1; i <= n + 1; i++) {
            ans = min(ans, up[i] + down[i - 1]);
            // cout << i << " " << ans << " " << up[i] << " " << down[i - 1] << " bruh\n";
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
