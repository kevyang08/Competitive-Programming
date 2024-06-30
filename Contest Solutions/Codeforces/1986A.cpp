#include <bits/stdc++.h>
using namespace std;

int t, x[3];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x[0] >> x[1] >> x[2];
        int ans = 30;
        for (int i = 1; i <= 10; i++) {
            int res = 0;
            for (int j : x) res += abs(i - j);
            ans = min(ans, res);
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