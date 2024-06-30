#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

long long q, l, r;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> q;
    while (q--) {
        cin >> l >> r;
        long long ans = 0;
        for (int i = 2; i < 60; i++) {
            long long lo = max((1LL << i), l), hi = min((1LL << (i + 1)) - 1, r);
            if (hi < lo) continue;
            for (long long j = 1, k = i; k <= hi; k *= i, j++) {
                if (hi/i < k) {
                    ans = (ans + (hi - max(k, lo) + 1)%M * j)%M;
                    break;
                }
                if (k * i - 1 >= lo) ans = (ans + (min(k * i - 1, hi) - max(k, lo) + 1)%M * j)%M;
            }
        }
        cout << ans << "\n";
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

/*
3
728 728
728 729
729 729
*/