#include <bits/stdc++.h>
using namespace std;

int t;
long long n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool ans = false;
        for (int k = 2; k < 63; k++) {
            long long l = 2, r = 1e9;
            while (l <= r) {
                long long m = (l + r)/2, res = 0;
                for (long long i = 0, j = 1; i <= k; i++, j *= m) {
                    if (i != k && (n - res)/m < j) {
                        res = n + 1;
                        break;
                    }
                    res += j;
                }
                if (res == n) {
                    ans = true;
                    break;
                }
                else if (res > n) r = m - 1;
                else l = m + 1;
            }
            if (ans) break;
        }
        cout << (ans ? "YES\n" : "NO\n");
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