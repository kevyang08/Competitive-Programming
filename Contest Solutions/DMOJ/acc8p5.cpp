#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int t, n, a[1000005];
long long bit[1000005], l[1000005], r[1000005];
void update(int i, long long v) {
    for (; i <= n; i += (i & -i)) bit[i] = (bit[i] + v)%MOD;
}
long long query(int i) {
    long long res = 0;
    for (; i > 0; i -= (i & -i)) res = (res + bit[i])%MOD;
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            l[i] = r[i] = 1;
            l[i] += query(a[i]); l[i] %= MOD;
            update(a[i] + 1, l[i]);
        }
        for (int i = 1; i <= n + 1; i++) bit[i] = 0;
        for (int i = n; i > 0; i--) {
            r[i] += query(a[i]); r[i] %= MOD;
            update(a[i] + 1, r[i]);
            ans = (ans + l[i] * r[i])%MOD;
        }
        for (int i = 1; i <= n + 1; i++) bit[i] = 0;
        cout << ans << "\n";
    }
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure question was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
