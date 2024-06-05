#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], b[200001];
int solve(int idx) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = 3; i <= n; i++) {
        if (__gcd(b[i - 2], b[i - 1]) > __gcd(b[i], b[i - 1])) {
            if (cnt) return 0x3f3f3f3f;
            cnt++;
            if (idx) {
                if (i > 3 && __gcd(b[i - 3], b[i - idx]) > __gcd(b[i - idx], b[i])) return 0x3f3f3f3f;
                if (i > 4 && __gcd(b[i - 4], b[i - 3]) > __gcd(b[i - 3], b[i - idx])) return 0x3f3f3f3f;
                if (idx == 2) b[i - 1] = b[i - 2];
            }
            else b[i] = b[i - 1], b[i - 1] = b[i - 2];
        }
    }
    return cnt;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = min(solve(0), min(solve(1), solve(2)));
        cout << (ans < 2 ? "YES\n" : "NO\n");
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
