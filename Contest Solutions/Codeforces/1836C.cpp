#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;
long long k;
void solve() {
    cin >> a >> b >> c >> k;
    int n = pow(10, a);
    long long p = 0;
    for (int x = pow(10, a - 1); x < n; x++) {
        int y = pow(10, b - 1), z = x + y;
        if (z < pow(10, c - 1)) {
            y += pow(10, c - 1) - z;
            z = pow(10, c - 1);
        }
        // cout << x << " " << y << " " << z << " debug\n";
        if (z >= pow(10, c) || y >= pow(10, b)) continue;
        ++p;
        if (p + min(pow(10, c) - z - 1, pow(10, b) - y - 1) >= k) {
            cout << x << " + " << y + k - p << " = " << z + k - p << "\n";
            return;
        }
        p += min(pow(10, c) - z - 1, pow(10, b) - y - 1);
    }
    cout << "-1\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
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