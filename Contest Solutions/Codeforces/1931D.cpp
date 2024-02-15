#include <bits/stdc++.h>
using namespace std;
 
int t, n, x, y, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        map<pair<int, int>, int> mp;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i]%x) ans += mp[{x - a[i]%x, a[i]%y}];
            else ans += mp[{0, a[i]%y}];
            if (mp.find({a[i]%x, a[i]%y}) == mp.end()) mp.insert({{a[i]%x, a[i]%y}, 0});
            mp[{a[i]%x, a[i]%y}]++;
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
