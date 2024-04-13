#include <bits/stdc++.h>
using namespace std;

int t, n, a[300005], psa[300005], rpsa[300005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool thing = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != a[1]) thing = false;
            psa[i] = rpsa[i] = 0;
            if (a[i] == a[i - 1]) psa[i] = psa[i - 1] + 1;
        }
        if (thing) {
            cout << "-1\n";
            continue;
        }
        int ans = 0x3f3f3f3f;
        rpsa[n + 1] = 0;
        for (int i = n; i > 0; i--) {
            if (a[i] == a[i + 1]) rpsa[i] = rpsa[i + 1] + 1;
            if (a[i - 1] == a[i + 1] && a[i] != a[i - 1]) ans = min(ans, min(psa[i - 1], rpsa[i + 1]) + 1);
        }
        if (a[1] == a[n]) ans = min(ans, min(rpsa[1], psa[n]) + 1);
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
