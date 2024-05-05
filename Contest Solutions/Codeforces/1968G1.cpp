#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int t, n, k, _, R = 257, R2 = 127;
string s;
long long h[200005], p[200005], h2[200005], p2[200005];
long long hsh(int l, int r) {
    return (h[r] - (h[l] * p[r - l])%M + M)%M;
}
long long hsh2(int l, int r) {
    return (h2[r] - (h2[l] * p2[r - l])%M + M)%M;
}
bool check(int m) {
    int cnt = 0;
    for (int i = m; i <= n; i++) {
        if (hsh(i - m, i) == hsh(0, m) && hsh2(i - m, i) == hsh2(0, m)) {
            cnt++;
            i += m - 1;
        }
    }
    return cnt >= k;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    p[0] = p2[0] = 1;
    for (int i = 1; i < 200005; i++) p[i] = (p[i - 1] * R)%M;
    for (int i = 1; i < 200005; i++) p2[i] = (p2[i - 1] * R2)%M;
    cin >> t;
    while (t--) {
        cin >> n >> k >> _ >> s;
        if (k == 1) {
            cout << n << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) h[i] = (h[i - 1] * R + s[i - 1])%M;
        for (int i = 1; i <= n; i++) h2[i] = (h2[i - 1] * R2 + s[i - 1])%M;
        int ans = 0, l = 1, r = n/k;
        while (l <= r) {
            int m = (l + r)/2;
            if (check(m)) {
                ans = m;
                l = m + 1;
            }
            else r = m - 1;
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
