#include <bits/stdc++.h>
using namespace std;

int t, n, m;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int mnr = 0x3f3f3f3f, mxr = 0, mnc = 0x3f3f3f3f, mxc = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < m; j++) if (s[j] == '#') {
                mnr = min(mnr, i);
                mxr = max(mxr, i);
                mnc = min(mnc, j);
                mxc = max(mxc, j);
            }
        }
        cout << (mnr + mxr)/2 + 1 << " " << (mnc + mxc)/2 + 1 << "\n";
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