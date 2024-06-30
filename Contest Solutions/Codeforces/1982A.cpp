#include <bits/stdc++.h>
using namespace std;

int t, x1, y_1, x2, y2;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x1 >> y_1 >> x2 >> y2;
        if (x1 > y_1 && x2 > y2 || x1 < y_1 && x2 < y2) cout << "YES\n";
        else cout << "NO\n";
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