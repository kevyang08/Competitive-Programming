#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        string ans = "YES\n";
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2; i < n; i++) {
            if (2 * a[i - 1] > a[i] or a[i - 1] > a[i + 1]) ans = "NO\n";
            a[i] -= 2 * a[i - 1]; a[i + 1] -= a[i - 1];
            if (i == n - 1 && (a[i + 1] | a[i])) ans = "NO\n";
        }
        cout << ans;
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
