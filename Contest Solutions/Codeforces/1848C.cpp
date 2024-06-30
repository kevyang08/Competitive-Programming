#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1848/problem/C

- if abs(a[i] - b[i]) < min(a[i], b[i]) perform operation once
    - this is the same as max(a[i], b[i]) < 2 * min(a[i], b[i])
- after 3 operations, max(a[i], b[i]) = abs(abs(a[i] - b[i]) - min(a[i], b[i])), min(a[i], b[i]) remains unchanged
- perform repeat 3 operations until min becomes max
- repeat process

- notice that each time we repeat this process, min gets reduced by at least half
- process should only repeat at most logmax(a[i], b[i]) times
*/

int t, n, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ans(3), arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (auto &a : arr) {
            int cnt = 0;
            cin >> b;
            if (!a && !b) {
                for (auto &j : ans) ++j;
                continue;
            }
            while (a && b) {
                while (max(a, b) < 2 * min(a, b)) {
                    ++cnt;
                    int temp = a;
                    a = b;
                    b = abs(temp - b);
                }
                if (!a || !b) break;
                if (a > b) {
                    cnt += a/(2 * b) * 3;
                    a %= 2 * b;
                }
                else {
                    cnt += b/(2 * a) * 3;
                    b %= 2 * a;
                }
            }
            if (a) ++cnt;
            ans[cnt%3]++;
        }
        cout << (ans[0] == n || ans[1] == n || ans[2] == n ? "YES\n" : "NO\n");
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