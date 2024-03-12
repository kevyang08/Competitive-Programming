#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, b, c, a[2001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0;
        memset(a, 0, sizeof(a));
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> b;
            a[b]++;
        }
        for (int i = 1; i <= 2000; i++) a[i] += a[i - 1];
        for (int i = 1; i <= m; i++) {
            cin >> c;
            if (k > c) ans += a[k - c];
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
