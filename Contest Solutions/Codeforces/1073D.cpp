#include <bits/stdc++.h>
using namespace std;

// using mod, t will be usable at most logt times

int n;
long long t, a[200001], mn = 0x3f3f3f3f;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    long long ans = 0;
    while (t >= mn) {
        long long s = 0, cnt = 0;
        for (int i = 1; i <= n; i++) if (a[i] <= t) {
            s += a[i];
            ++cnt;
        }
        ans += t/s * cnt;
        t %= s;
        for (int i = 1; i <= n; i++) {
            if (a[i] > t) continue;
            ans++;
            t -= a[i];
        }
    }
    cout << ans << "\n";
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