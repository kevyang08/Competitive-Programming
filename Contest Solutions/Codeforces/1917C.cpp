#include <bits/stdc++.h>
using namespace std;

int t, n, k, d;
vector<int> a, v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> d;
        int ans = 0;
        a.resize(n);
        v.resize(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> v[i];
        for (int i = 1; i <= min(d, 2 * n); i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) if (a[j - 1] == j) cnt++;
            ans = max(ans, (d - i)/2 + cnt);
            for (int j = 0; j < v[(i - 1)%k]; j++) a[j]++;
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