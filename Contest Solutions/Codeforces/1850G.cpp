#include <bits/stdc++.h>
using namespace std;

int t, n, x, y;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, long long> mp[4];
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            mp[0][x]++;
            mp[1][y]++;
            mp[2][y - x]++;
            mp[3][y + x]++;
        }
        for (int i = 0; i < 4; i++) for (auto &[a, b] : mp[i]) ans += b * b - b;
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