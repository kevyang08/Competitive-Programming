#include <bits/stdc++.h>
using namespace std;
 
int t, n, m, k, r[200001], c[200001], pra[200001], pca[200001], nra[200001];
bool thing[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        map<int, set<pair<int, int>>, greater<int>> mp;
        cin >> n >> m >> k;
        long long ans = 0;
        mp.emplace(0, set<pair<int, int>>());
        mp[0].insert({0, 0});
        for (int i = 1; i <= k; i++) {
            thing[i] = false;
            cin >> r[i] >> c[i];
            mp.emplace(r[i], set<pair<int, int>>());
            mp[r[i]].insert({c[i], i});
        }
        long long pr = n, pc = m + 1;
        int pdx = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it -> second.begin() -> first >= pc) continue;
            ans += (pc - 1) * (pr - it -> first);
            thing[it -> second.begin() -> second] = true;
            pra[it -> second.begin() -> second] = pr;
            pca[it -> second.begin() -> second] = pc;
            pc = static_cast<long long>(it -> second.begin() -> first);
            pr = it -> first;
            nra[pdx] = pr;
            pdx = it -> second.begin() -> second;
        }
        cout << ans << "\n";
        for (int i = 1; i <= k; i++) {
            if (thing[i]) {
                long long res = 0, pres = (pca[i] - 1LL) * (pra[i] - r[i]) + (c[i] - 1LL) * (r[i] - nra[i]);
                pr = pra[i], pc = pca[i];
                auto temp = *mp[r[i]].begin();
                mp[r[i]].erase(temp);
                for (auto it = mp.lower_bound(r[i]); it != mp.end() && it -> first >= nra[i]; it++) {
                    if (it -> second.empty() || it -> second.begin() -> first >= pc) continue;
                    res += (pc - 1) * (pr - it -> first);
                    pc = static_cast<long long>(it -> second.begin() -> first);
                    pr = it -> first;
                }
                mp[r[i]].insert(temp);
                cout << res - pres;
            }
            else cout << 0;
            cout << (i == k ? "\n" : " ");
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
