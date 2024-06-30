#include <bits/stdc++.h>
using namespace std;

int t, x, y, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        while (x >= y && k) {
            x++; k--;
            int temp = 0;
            if (x%y) {
                temp = x/y * y + y - x;
                x += min(temp, k);
            }
            k = max(k - temp, 0);
            while (x%y == 0) x /= y;
        }
        if (k) {
            int temp = min(k, y - x);
            x += temp;
            k -= temp;
            if (x == y) x = 1;
            x += k%(y - 1);
        }
        cout << x << "\n";
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