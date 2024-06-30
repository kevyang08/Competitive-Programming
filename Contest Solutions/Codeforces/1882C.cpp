#include <bits/stdc++.h>
using namespace std;

int t, n, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n >> a;
        if (n > 1) cin >> ans;
        ans = max(max(ans, 0LL) + a, 0LL);
        for (int i = 2; i < n; i++) {
            cin >> a;
            ans = max(ans, ans + a);
        }
        cout << ans << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/