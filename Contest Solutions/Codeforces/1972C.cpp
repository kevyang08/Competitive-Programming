#include <bits/stdc++.h>
using namespace std;

// bruh spent an hour just to realize that i have to use greater<long long> instead of greater<int> to sort properly
// otherwise this would've been first ac shortly into the contest

int t, n;
long long a[200001], k;
bool check(long long m) {
    long long res = 0;
    for (int i = 1; i <= n; i++) res += max(0LL, m/n + (i <= m%n ? 1 : 0) - a[i]);
    return res <= k;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        sort(a + 1, a + n + 1, greater<long long>());
        long long l = 1, r = 0x3f3f3f3f3f3f3f3f;
        while (l < r) {
            long long m = (l + r + 1)/2;
            if (check(m)) l = m;
            else r = m - 1;
        }
        cout << l - n + 1 << "\n";
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
