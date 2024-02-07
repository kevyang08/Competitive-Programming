// could just keep track of low and high to lower time and memory complexity
// also ignore test case below

#include <bits/stdc++.h>
using namespace std;
 
int t, n, k, ans[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        set<int> sl;
        set<int, greater<int>> sr;
        for (int i = 1; i <= n; i++) {
            sl.insert(i);
            sr.insert(i);
        }
        for (int i = 1; i <= k; i++) {
            if (i%2) {
                ans[i] = *sl.lower_bound(1);
                sl.erase(ans[i]);
                sr.erase(ans[i]);
                for (int j = k + i; j <= n; j += k) {
                    ans[j] = ans[j - k] + 1;
                    sl.erase(ans[j]);
                    sr.erase(ans[j]);
                }
            }
            else {
                ans[i] = *sr.lower_bound(n);
                sl.erase(ans[i]);
                sr.erase(ans[i]);
                for (int j = k + i; j <= n; j += k) {
                    ans[j] = ans[j - k] - 1;
                    sl.erase(ans[j]);
                    sr.erase(ans[j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? "\n" : " ");
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
 
/*
10 4
1 10 3 8 2 9 4 7 
*/
