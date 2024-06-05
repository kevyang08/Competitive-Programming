#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = n, cur = n + 1, temp = max(m - 1, 0);
        while (temp >= (cur & -cur)) {
            temp -= (cur & -cur);
            cur += (cur & -cur);
        }
        if (m) ans |= cur - 1, ans |= cur;
        if (n) {
            cur = n - 1, temp = max(m - 1, 0);
            int prev = cur;
            while (cur > 0 && temp >= (cur & -cur)) {
                temp -= (cur & -cur);
                prev = cur;
                cur -= (cur & -cur);
            }
            if (temp && cur) {
                ans |= cur - 1;
                ans |= cur;
            }
            else if (m) {
                if (m > 1) ans |= max(prev - 1, 0);
                ans |= max(prev, 0);
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
