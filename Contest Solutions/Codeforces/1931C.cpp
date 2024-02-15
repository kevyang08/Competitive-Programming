#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0, pref = 0, suf = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == a[1] && pref == i - 1) pref++;
        }
        if (pref == n) {
            cout << "0\n";
            continue;
        }
        for (int i = n; i > 0 && a[i] == a[n]; i--) suf++;
        if (a[1] == a[n]) cout << n - pref - suf << "\n";
        else cout << n - max(pref, suf) << "\n";
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
