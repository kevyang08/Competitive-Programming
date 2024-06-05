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
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            int l = 0;
            for (int j = 0; j + i < s.length(); j++) {
                if (s[j] == s[j + i] || s[j] == '?' || s[j + i] == '?') ++l;
                else l = 0;
                if (l == i) {
                    ans = l * 2;
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
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
