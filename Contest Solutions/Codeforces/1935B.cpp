#include <bits/stdc++.h>
using namespace std;

int t, n, a, idx[2][100001];
void solve() {
    int l = 1, r = n;
    for (int i = 0; i < n; i++) {
        if (!idx[1][i]) break;
        else if (idx[0][i] == idx[1][i]) {
            cout << "-1\n";
            return;
        }
        else {
            if (idx[0][i] > r || idx[1][i] < l) {
                cout << "-1\n";
                return;
            }
            l = max(idx[0][i], l);
            r = min(idx[1][i], r);
        }
    }
    cout << "2\n";
    cout << "1 " << r - 1 << "\n";
    cout << r << " " << n << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) idx[0][i] = 0x3f3f3f3f, idx[1][i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            idx[0][a] = min(idx[0][a], i);
            idx[1][a] = max(idx[1][a], i);
        }
        solve();
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