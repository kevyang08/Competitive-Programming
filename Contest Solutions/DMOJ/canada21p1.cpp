#include <bits/stdc++.h>
using namespace std;

int t, n, a[750001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = n;
        for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (s[i - 1] == 'W');
        for (int i = 2, j = 1; i < n; i++) {
            ans = min(ans, a[j] + i - j - a[i] + a[j] + a[n] - a[i]);
            if (i - j - a[i] + a[j] >= a[i] - a[j]) j = i;
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