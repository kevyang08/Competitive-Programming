#include <bits/stdc++.h>
using namespace std;

int t, x, y;
void solve() {
    for (int i = 0; i < 31; i++) {
        int temp = 1 << i;
        if ((x & temp) != (y & temp)) {
            cout << (1 << i) << "\n";
            return;
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        solve();
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