#include <bits/stdc++.h>
using namespace std;

int t, n, c[200001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int cn = 0, cp = 0, b = 0;
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '(') {
                c[i] = 1 + (b < 0);
                if (!b) cp = 1;
                ++b;
            }
            else {
                c[i] = 2 - (b > 0);
                if (!b) cn = 1;
                --b;
            }
        }
        if (b) cout << "-1\n";
        else {
            cout << cn + cp << "\n";
            for (int i = 1; i <= n; i++) cout << (min(cn + cp, c[i])) << (i == n ? "\n" : " ");
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