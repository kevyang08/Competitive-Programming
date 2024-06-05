#include <bits/stdc++.h>
using namespace std;

int t, n, b, c[200001];
long long x;
long long solve(int k) {
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        long long cnt = 0;
        for (int j = 0; j < c[i]; j++) {
            if (j%k) cnt += b;
            res += cnt;
        }
    }
    return max(res - k * x + x, 0LL);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> b >> x;
        int l = 1, r = 0;
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) r = max(r, c[i]);
        while (l <= r) {
            int m1 = l + (r - l)/3, m2 = r - (r - l)/3;
            if (solve(m1) < solve(m2)) l = m1 + 1;
            else r = m2 - 1;
        }
        cout << solve(l) << "\n";
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
