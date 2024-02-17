#include <bits/stdc++.h>
using namespace std;

int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < 2 * n; i += 2) ans += a[i];
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
