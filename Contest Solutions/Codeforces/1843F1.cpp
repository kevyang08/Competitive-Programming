#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c, cmx[200005], cmn[200005], mx[200005], mn[200005];
char op;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    cmx[1] = mx[1] = 1;
    while (t--) {
        cin >> n;
        int sz = 1;
        while (n--) {
            cin >> op >> a >> b;
            if (op == '+') {
                ++sz;
                cmx[sz] = max(0, cmx[a] + b);
                cmn[sz] = min(0, cmn[a] + b);
                mx[sz] = max(cmx[sz], mx[a]);
                mn[sz] = min(cmn[sz], mn[a]);
            }
            else {
                cin >> c;
                if (c > 0) cout << (mx[b] >= c ? "YES\n" : "NO\n");
                else cout << (mn[b] <= c ? "YES\n" : "NO\n");
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