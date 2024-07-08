#include <bits/stdc++.h>
using namespace std;

int t, n, a[5001], dp[5001], bit[5001];
void update(int i, int v) {
    for (; i > 0; i -= (i & -i)) bit[i] = min(bit[i], v);
}
int query(int i) {
    int res = 0x3f3f3f3f;
    for (; i <= n; i += (i & -i)) res = min(res, bit[i]);
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) {
            vector<int> v{i};
            dp[i] = 0;
            int mn = 0x3f3f3f3f;
            memset(bit, 0x3f3f3f3f, sizeof(bit));
            for (int j = i + 1; j <= n; j++) {
                if (a[j] >= a[v.back()]) {
                    mn = 0x3f3f3f3f;
                    if (a[j] > a[v.back()]) v.push_back(j);
                }
                else {
                    int l = 0, r = v.size() - 1;
                    while (l < r) {
                        int m = (l + r)/2;
                        if (a[v[m]] > a[j]) r = m;
                        else l = m + 1;
                    }
                    mn = min(v[r], query(v[r]));
                }
                if (mn == 0x3f3f3f3f) dp[j] = dp[j - 1];
                else dp[j] = j - mn + dp[mn - 1];
                ans += dp[j];
                update(j, mn);
            }
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