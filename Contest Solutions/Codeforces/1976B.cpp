#include <bits/stdc++.h>
using namespace std;

int t, n, a[200005], b[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans = 0, bruh = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n + 1; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            ans += abs(a[i] - b[i]);
            if (min(a[i], b[i]) <= b[n + 1] && b[n + 1] <= max(a[i], b[i])) bruh = 0;
            else if (b[n + 1] > max(a[i], b[i])) bruh = min(bruh, (long long)b[n + 1] - max(a[i], b[i]));
            else bruh = min(bruh, (long long)min(a[i], b[i]) - b[n + 1]);
        }
        cout << ans + bruh + 1 << "\n";
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
