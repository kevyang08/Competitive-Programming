#include <bits/stdc++.h>
using namespace std;

int t, n, k, p[200001], a[200001], b, s;
long long solve(int st) {
    long long ans = 0, prev = 0;
    int x = st;
    for (long long i = 0; i < min(k, n); i++) {
        ans = max(ans, prev + a[x] * (k - i));
        prev += a[x];
        x = p[x];
    }
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> b >> s;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> a[i];
        long long p1 = solve(b), p2 = solve(s);
        cout << (p1 == p2 ? "Draw" : p1 > p2 ? "Bodya" : "Sasha") << "\n";
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
