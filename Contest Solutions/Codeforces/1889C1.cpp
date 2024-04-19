#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, l, r, a[200005], a1[200005], a2[200005];
vector<pair<int, int>> v;
deque<pair<int, int>> dq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0, mx = 0, c0 = 0;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) a[i] = 0;
        for (int i = 1; i <= m; i++) {
            cin >> l >> r;
            a[l]++, a[r + 1]--;
            v.push_back({l, r});
        }
        sort(v.begin(), v.end());
        for (int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
            if (!a[i]) c0++;
            a1[i] = a1[i - 1] + (a[i] == 1);
            a2[i] = a2[i - 1] + (a[i] == 2);
        }
        for (auto &[l, r] : v) {
            while (!dq.empty() && dq.front().second < l) {
                mx = max(mx, dq.front().first);
                dq.pop_front();
            }
            int c1 = a1[r] - a1[l - 1];
            ans = max(ans, mx + c1);
            if (!dq.empty()) ans = max(ans, c1 + dq.front().first + a2[min(dq.front().second, r)] - a2[l - 1]);
            while (!dq.empty() && dq.back().first + a2[dq.back().second] - a2[l - 1] <= c1 + a2[r] - a2[l - 1]) {
                mx = max(mx, dq.back().first);
                dq.pop_back();
            }
            dq.push_back({c1, r});
        }
        cout << ans + c0 << "\n";
        dq.clear();
        v.clear();
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
