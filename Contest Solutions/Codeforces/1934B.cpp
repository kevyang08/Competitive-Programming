#include <bits/stdc++.h>
using namespace std;

int t, n, ans[30], a[5] = {1, 3, 6, 10, 15};
void bruh() {
    memset(ans, 0x3f3f3f3f, sizeof(ans));
    ans[0] = 0;
    for (int i = 0; i < 30; i++) {
        for (int k = 0; k < 5; k++) {
            if (i + a[k] < 30) ans[i + a[k]] = min(ans[i + a[k]], ans[i] + 1);
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    bruh();
    while (t--) {
        cin >> n;
        if (n >= 30) {
            int res = 0x3f3f3f3f;
            for (int i = 0; i < 30; i++) {
                n -= i;
                res = min(res, ans[i] + n/15 + n%15/10 + n%15%10/6 + n%15%10%6/3 + n%15%10%6%3);
                n += i;
            } 
            cout << res << "\n";
        }
        else cout << ans[n] << "\n";
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