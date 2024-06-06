#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1714/problem/F

- get min(d1, d2, d3) and check if theres somewhere along the path that the remaining node can fit
    - if yes make tree
    - else no
*/

int t, n, d[5][5];
void solve(int r, int l1, int l2, int j) {
    // cout << r << " " << l1 << " " << l2 << " " << j << " bruh\n";

    cout << "YES\n";
    int cur = 4, pre = r;
    for (int i = 0; i < j - (j == d[r][l1]); i++) {
        cout << pre << " " << cur << "\n";
        pre = cur++;
    }
    for (int i = j + 1; i < d[r][l1]; i++) {
        cout << pre << " " << cur << "\n";
        pre = cur++;
    }
    cout << pre << " " << l1 << "\n";
    pre = (j ? j == d[r][l1] ? l1 : 3 + j : r);
    for (int i = j + 1; i < d[r][l2]; i++) {
        cout << pre << " " << cur << "\n";
        pre = cur++;
    }
    cout << pre << " " << l2 << "\n";
    while (cur <= n) cout << 1 << " " << cur++ << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> d[1][2] >> d[2][3] >> d[3][1];
        d[2][1] = d[1][2], d[3][2] = d[2][3], d[1][3] = d[3][1];
        int r = (d[1][2] < min(d[2][3], d[3][1]) ? 1 : d[2][3] < d[3][1] ? 2 : 3), l1 = r%3 + 1, l2 = 6 - r - l1, mn = min(d[1][2], min(d[2][3], d[3][1]));
        bool thing = false;
        for (int i = 0; i <= mn; i++) if (mn + 1 + d[l2][r] - i <= n && d[l2][r] - i == d[l2][l1] + i - mn) thing = true, solve(r, l1, l2, i);
        if (!thing) cout << "NO\n";
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
