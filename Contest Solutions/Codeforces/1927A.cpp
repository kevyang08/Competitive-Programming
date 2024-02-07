#include <bits/stdc++.h>
using namespace std;
 
int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n, mn = 69, mx = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        cout << mx - mn + 1 << "\n";
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
