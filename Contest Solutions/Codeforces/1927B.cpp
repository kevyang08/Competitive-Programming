// did not need binary search

#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[200001], cnt[26];
char ans[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        char cur = 'a';
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (!a[i]) {
                cnt[cur - 'a']++;
                ans[i] = cur++;
            }
            else {
                int l = 0, r = 25, idx = 25;
                while (l <= r) {
                    int m = (l + r)/2;
                    if (cnt[m] > a[i]) l = m + 1;
                    else {
                        idx = min(m, idx);
                        r = m - 1;
                    }
                }
                cnt[idx]++;
                ans[i] = 'a' + idx;
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << "\n";
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
