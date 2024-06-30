#include <bits/stdc++.h>
using namespace std;

int t;
long long x;
void check() {
    long long y = 1e18, carry = 1;
    while (y > x) y /= 10;
    // cout << y << " debug\n";
    if (x/y != 1) {
        cout << "NO\n";
        return;
    }
    for (; y > 0; y /= 10) {
        if (!carry) {
            cout << "NO\n";
            return;
        }
        if (!(x/y)) carry = 0;
        x -= x/y * y;
    }
    cout << "YES\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x;
        if (x%10 == 9) {
            cout << "NO\n";
            continue;
        }
        check();
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