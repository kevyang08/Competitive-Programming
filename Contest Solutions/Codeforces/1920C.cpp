#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001];
int gcd(int a, int b) {
    return a%b == 0 ? b : gcd(b, a%b);
}
bool solve(int k) {
    if (k == n) return true;
    int m = 0;
    for (int i = 1; i <= k; i++) {
        int mx = 0, bruh = 0;
        for (int j = i; j <= n; j += k) mx = max(mx, a[j]);
        for (int j = i; j <= n; j += k) {
            if (!bruh && mx != a[j]) bruh = mx - a[j];
            else if (mx != a[j]) bruh = gcd(bruh, mx - a[j]);
        }
        if (bruh && !m) m = bruh;
        else if (bruh && m) m = gcd(m, bruh);
    }
    return m != 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i * i <= n; i++) {
            if (n%i) continue;
            ans += solve(i);
            if (i != n/i) ans += solve(n/i);
        }
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
