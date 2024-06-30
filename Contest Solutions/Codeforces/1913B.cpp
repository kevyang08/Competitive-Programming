#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0, c0 = 0, c1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') c0++;
            else c1++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                if (c1) --c1;
                else {
                    ans = s.length() - i;
                    break;
                }
            }
            else {
                if (c0) --c0;
                else {
                    ans = s.length() - i;
                    break;
                }
            }
        }
        cout << ans << "\n";
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