#include <bits/stdc++.h>
using namespace std;

int t, n, k, a, b;
long long x[200001], y[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> a >> b;
        for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
        if (a <= k && b <= k) cout << "0\n";
        else {
            long long ans = abs(x[a] - x[b]) + abs(y[a] - y[b]), d1 = 0x3f3f3f3f3f3f3f3f, d2 = d1;
            for (int i = 1; i <= k; i++) {
                d1 = min(d1, abs(x[a] - x[i]) + abs(y[a] - y[i]));
                d2 = min(d2, abs(x[b] - x[i]) + abs(y[b] - y[i]));
            }
            cout << min(ans, d1 + d2) << "\n";
        }
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