#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000001], b[1000001], c[1000001];
long long ans = 0, dp[1000001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    vector<pair<int, int>> v, dq;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        v.push_back({a[i] - b[i], a[i]});
    }
    sort(v.begin(), v.end());
    // precompute the ans for each height
    for (auto p : v) if (dq.empty() || dq.back().second > p.second) dq.push_back(p);
    int idx = dq.size() - 1;
    for (int i = dq.back().second; i <= dq.front().second; i++) {
        if (idx > 0 && i >= dq[idx - 1].second) --idx;
        dp[i] += (i - dq[idx].second)/dq[idx].first * 2 + 2;
        int temp = i - ((i - dq[idx].second)/dq[idx].first + 1) * dq[idx].first;
        dp[i] += dp[temp];
        
        // cout << i << " " << dp[i] << " " << temp << " bruh\n";
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        if (c[i] > dq.front().second) {
            ans += (c[i] - dq[0].second)/dq[0].first * 2 + 2;
            int temp = c[i] - ((c[i] - dq[0].second)/dq[0].first + 1) * dq[0].first;
            ans += dp[temp];
        }
        else ans += dp[c[i]];
    }
    cout << ans << "\n";
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