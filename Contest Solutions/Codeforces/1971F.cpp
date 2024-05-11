#include <bits/stdc++.h>
using namespace std;

int t, r;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> r;
        long long a = (long long)r * r, b = (r + 1LL) * (r + 1);
        int ans = 0;
        for (int i = 0; i <= r; i++) {
            int ll = 1, rr = r, lo;
            long long i2 = (long long)i * i;
            while (ll < rr) {
                int m = (ll + rr)/2;
                if (a <= i2 + (long long)m * m) rr = m;
                else ll = m + 1;
            }
            lo = rr;
            ll = 1, rr = r;
            while (ll < rr) {
                int m = (ll + rr + 1)/2;
                if (i2 + (long long)m * m < b) ll = m;
                else rr = m - 1;
            }
            ans += ll - lo + 1;
        }
        cout << ans * 4 << "\n";
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
