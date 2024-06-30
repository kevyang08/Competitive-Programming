#include <bits/stdc++.h>
using namespace std;

int t, n, p;
vector<pair<int, int>> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> p;
        v.resize(n);
        long long ans = p;
        for (int i = 0; i < n; i++) cin >> v[i].second;
        for (int i = 0; i < n; i++) v[i].second = -v[i].second;
        for (int i = 0; i < n; i++) cin >> v[i].first;
        sort(v.begin(), v.end());

        for (int i = 0, c = 1; i < n; i++) {
            if (v[i].first < p) {
                ans += (long long)v[i].first * min(-v[i].second, n - c);
                c = min(n, c - v[i].second);
            }
            else {
                ans += (long long)p * (n - c);
                break;
            }
        }
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