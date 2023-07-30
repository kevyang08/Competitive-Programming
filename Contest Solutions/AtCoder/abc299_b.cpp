#include <bits/stdc++.h>
using namespace std;
 
int n, t, c[200000], r, ans;
map<int, vector<pair<int, int>>> m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        cin >> r;
        m.try_emplace(c[i], vector<pair<int, int>>());
        m[c[i]].push_back({r, i + 1});
    }
    if (m.find(t) == m.end()) t = c[0];
    sort(m[t].begin(), m[t].end());
    ans = m[t][m[t].size() - 1].second;
    cout << ans << "\n";
    return 0;
}
