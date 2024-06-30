#include <bits/stdc++.h>
using namespace std;

int t, n, l, r, a[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        long long cur = 0, ans = 0;
        for (int i = 1, j = 1; i <= n; i++) {
            cin >> a[i];
            cur += a[i];
            while (cur > r && j <= i) cur -= a[j++];
            if (cur >= l && cur <= r) {
                cur = 0;
                ans++;
                j = i + 1;
            }
        }
        cout << ans << "\n";
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