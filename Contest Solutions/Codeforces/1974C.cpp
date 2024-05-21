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
        long long ans = 0;
        map<tuple<int, int, int>, int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i < 3) continue;
            ans += mp[{a[i - 2], a[i - 1], 0}] + mp[{a[i - 2], 0, a[i]}] + mp[{0, a[i - 1], a[i]}] - 3 * mp[{a[i - 2], a[i - 1], a[i]}];
            mp[{a[i - 2], a[i - 1], 0}]++; mp[{a[i - 2], 0, a[i]}]++; mp[{0, a[i - 1], a[i]}]++; mp[{a[i - 2], a[i - 1], a[i]}]++;
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
