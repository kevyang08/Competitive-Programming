#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, r, c;
bool thing[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        map<int, set<pair<int, int>>> mp;
        cin >> n >> m >> k;
        long long ans = 0;
        for (int i = 1; i <= k; i++) {
            thing[i] = false;
            cin >> r >> c;
            mp.emplace(r, set<pair<int, int>>());
            mp[r].insert({c, i});
        }
        long long pr = n, pc = m + 1;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            ans += (pc - 1) * (pr - it -> first);
            if (it -> second.begin() -> first < pc) thing[it -> second.begin() -> second] = true;
            pc = min(pc, static_cast<long long>(it -> second.begin() -> first));
            pr = it -> first;
        }
        ans += (pc - 1) * pr;
        cout << ans << "\n";
        for (int i = 1; i <= k; i++) cout << thing[i] << (i == k ? "\n" : " ");
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
