#include <bits/stdc++.h>
using namespace std;

int t, n, a[300005], diff[300005];
long long psa[300005];
int bsl(int i) {
    int l = 1, r = i - 2, idx = -1;
    while (l <= r) {
        int m = (l + r)/2;
        if (psa[i - 1] - psa[m - 1] > a[i] && diff[i - 1] - diff[m] > 0) {
            idx = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return idx;
}
int bsr(int i) {
    int l = i + 2, r = n, idx = -1;
    while (l <= r) {
        int m = (l + r)/2;
        if (psa[m] - psa[i] > a[i] && diff[m] - diff[i + 1] > 0) {
            idx = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return idx;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            psa[i] = a[i] + psa[i - 1];
            if (i > 1) diff[i] = (a[i] != a[i - 1]) + diff[i - 1];
        }
        a[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            int l = bsl(i), r = bsr(i);
            if (max(a[i - 1], a[i + 1]) > a[i]) cout << 1;
            else if (l != -1 && r != -1) cout << min(i - l, r - i);
            else if (l != -1) cout << i - l;
            else if (r != -1) cout << r - i;
            else cout << -1;
            cout << (i == n ? "\n" : " ");
        }
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
