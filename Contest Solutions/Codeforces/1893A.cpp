#include <bits/stdc++.h>
using namespace std;

int t, n, k, b[200000];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string ans = "YES\n";
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0, idx = n - 1; i < min(n, k); i++) {
            if (b[idx] > n) ans = "NO\n";
            idx = (idx - b[idx] + n)%n;
        }
        cout << ans;
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