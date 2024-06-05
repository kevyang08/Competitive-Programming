#include <bits/stdc++.h>
using namespace std;

int t, n, k, q, x, a[200005], l[200005], r[200005];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int idx = 1;
        cin >> n >> k >> s;
        fill(a + 1, a + n + 2, 0);
        for (int i = 1; i <= k; i++) cin >> l[i];
        for (int i = 1; i <= k; i++) cin >> r[i];
        cin >> q;
        while (q--) {
            cin >> x;
            int lo = 1, hi = k;
            while (lo < hi) {
                int m = (lo + hi)/2;
                if (r[m] < x) lo = m + 1;
                else hi = m;
            }
            int rx = r[hi] + l[hi] - x;
            a[min(x, rx)]++; a[max(x, rx) + 1]--;
        }
        for (int i = 0; i < n; i++) {
            if (r[idx] <= i) idx++;
            a[i + 1] += a[i];
            cout << (a[i + 1]%2 ? s[r[idx] + l[idx] - i - 2] : s[i]);
        }
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
