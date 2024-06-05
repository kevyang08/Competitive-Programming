#include <bits/stdc++.h>
using namespace std;

int t;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        bool thing = false;
        int ca = 0, cb = 0, l = 0, pa = 0, pb = 0, ta = 0, tb = 0;
        for (char c : s) {
            if (c == 'A') l++;
            else {
                ta = ca, tb = cb;
                ca = max(l + ca, l + pb);
                if (thing) cb = max(l + cb, l + pa);
                pa = ta, pb = tb;
                l = 0;
                thing = true;
            }
        }
        if (l && thing) cb = max(l + cb, l + pa);
        cout << max(ca, cb) << "\n";
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
