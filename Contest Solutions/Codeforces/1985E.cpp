#include <bits/stdc++.h>
using namespace std;

int t, x, y, z;
long long k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x >> y >> z >> k;
        long long ans = 0;
        for (long long i = 1; i <= x; i++) {
            if (k%i) continue;
            for (long long j = 1; j <= y; j++) {
                if (k/i%j || k/i/j > z) continue;
                ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k/i/j + 1));
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