#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, d, a[200001];
long long arr[101];
long long solve(int r) {
    deque<pair<int, long long>> dq;
    dq.push_back({1, 1});
    for (int i = 2; i < m; i++) {
        if (dq.front().first < i - d - 1) dq.pop_front();
        long long temp = dq.front().second + a[i] + 1;
        while (!dq.empty() && dq.back().second >= temp) dq.pop_back();
        dq.push_back({i, temp});
    }
    if (dq.front().first < m - d - 1) dq.pop_front();
    return dq.front().second + 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0x3f3f3f3f3f3f3f3f;
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> a[j];
            arr[i] = solve(i) + arr[i - 1];
            if (i >= k) ans = min(ans, arr[i] - arr[i - k]);
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
1
1 8 1 1
0 10 4 8 4 4 2 0

*/

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
