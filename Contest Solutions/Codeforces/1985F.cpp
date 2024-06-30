#include <bits/stdc++.h>
using namespace std;

int t, h, n, a[200001], c[200001];
bool check(long long m) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += (m - 1)/c[i] * a[i] + a[i];
        if (res >= h) return true;
        // cout << i << " " << c[i] << " " << a[i] << " bruh\n";
    }
    return false;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> h >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        long long l = 1, r = 4e10;
        while (l < r) {
            long long m = (l + r)/2;
            // cout << m << " wtf\n";
            if (check(m)) r = m;
            else l = m + 1;
        }
        cout << r << "\n";
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