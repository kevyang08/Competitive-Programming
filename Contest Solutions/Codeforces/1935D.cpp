#include <bits/stdc++.h>
using namespace std;

int t, n;
long long s, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> c;
        long long p = 0, ans = 0, o = 0;
        bool thing = false;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (i == 0 && s) ans++;
            if (s - 1 > p) {
                ans += s - p - 1 + (s - 1) * (s - 1)/4 - p * p/4;
                long long oc = (s - p - 1)/2, ec = oc;
                if ((s - p - 1)%2) {
                    if ((p + 1)%2) oc++;
                    else ec++;
                }
                ans -= o * oc + (i - o) * ec;
            }
            // account for sums > c
            ans += (s + 1) * (s + 1)/4 - (p + 1) * (p + 1)/4;
            long long oc = (s - p)/2, ec = oc;
            if ((s - p)%2) {
                if ((c + c - p)%2) oc++;
                else ec++;
            }
            ans -= o * oc + (i - o) * ec;

            p = s;
            o += s%2;

            // cout << i << " " << ans << " bruh\n";
        }
        long long oc = 0, ec = 0;
        if (c > p) {
            ans += c - p + c * c/4 - p * p/4;
            oc = (c - p)/2, ec = oc;
            if ((c - p)%2) {
                if (c%2) oc++;
                else ec++;
            }
            ans -= o * oc + (n - o) * ec;
        }
        // account for sums > c
        ans += (c + 1) * (c + 1)/4 - (p + 1) * (p + 1)/4;
        oc = (c - p)/2, ec = oc;
        if ((c - p)%2) {
            if ((c + c - p)%2) oc++;
            else ec++;
        }
        ans -= o * oc + (n - o) * ec;
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
0 8
4 4
0 9
2 7
3 6
4 5
0 10
1 9
5 5

expected: 9
got: 11
*/

/*
n 0 1 2 3 4 5 6 7 8 9 10
p 0 0 1 1 2 2 3 3 4 4 5
s 0 0 1 2 4 6 9 12 16 20 25
*/