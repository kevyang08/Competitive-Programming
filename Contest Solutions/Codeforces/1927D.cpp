// could just use psa to lower time complexity

#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[200001], q, l, r;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        set<int> s;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1 && a[i] != a[i - 1]) s.insert(i - 1);
        }
        cin >> q;
        while (q--) {
            cin >> l >> r;
            if (s.lower_bound(l) != s.end() && *s.lower_bound(l) < r) {
                int idx = *s.lower_bound(l);
                cout << idx << " " << idx + 1 << "\n";
            }
            else cout << "-1 -1\n";
        }
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
