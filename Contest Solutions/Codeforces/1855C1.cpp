#include <bits/stdc++.h>
using namespace std;

// too lazy to solve the hard version rn but the idea should be somewhat similar

int t, n, a[21];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int l = 1, r = n, ldx = 1, rdx = n, pos = 0, neg = 0, pdx = n, ndx = 1;
        for (int i = 1; i <= n; i++) cin >> a[i];
        while (ldx <= n && a[ldx] <= 0) {
            if (a[ldx] < 0) l = ldx + 1;
            ldx++;
        }
        while (rdx >= l && a[rdx] >= 0) {
            if (a[rdx] > 0) r = rdx - 1;
            rdx--;
        }
        for (int i = l; i <= r; i++) {
            if (a[i] < 0) neg++, ndx = max(ndx, i);
            if (a[i] > 0) pos++, pdx = min(pdx, i);
        }
        if (!pos && !neg) {
            cout << max(n - r - 1, 0) + max(l - 2, 0) << "\n";
            for (int i = l - 1; i > 1; i--) cout << i - 1 << " " << i << "\n";
            for (int i = r + 1; i < n; i++) cout << i + 1 << " " << i << "\n";
        }
        else if (pos > neg) {
            cout << n - pdx + 5 + neg + max(l - 2, 0) << "\n";
            for (int i = l - 1; i > 1; i--) cout << i - 1 << " " << i << "\n";
            for (int i = 1; i <= 5; i++) cout << pdx << " " << pdx << "\n";
            for (int i = pdx + 1; i <= n; i++) {
                cout << i << " " << i - 1 << "\n";
                if (a[i] < 0) cout << i << " " << i - 1 << "\n";
            }
        }
        else {
            cout << ndx - 1 + 5 + pos + max(n - r - 1, 0) << "\n";
            for (int i = r + 1; i < n; i++) cout << i + 1 << " " << i << "\n";
            for (int i = 1; i <= 5; i++) cout << ndx << " " << ndx << "\n";
            for (int i = ndx - 1; i > 0; i--) {
                cout << i << " " << i + 1 << "\n";
                if (a[i] > 0) cout << i << " " << i + 1 << "\n";
            }
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
