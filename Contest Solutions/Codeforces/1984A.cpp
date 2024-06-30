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
        cin >> n;
        int mn = 0x3f3f3f3f, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }
        cout << (mn == mx ? "NO" : "YES\n");
        if (mn != mx) for (int i = 0; i < n; i++) cout << (i == n/2 ? "R" : "B");
        cout << "\n";
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