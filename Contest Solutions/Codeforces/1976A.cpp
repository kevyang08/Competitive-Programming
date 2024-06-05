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
        cin >> n >> s;
        bool thing = true;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] > s[i] && !('0' <= s[i - 1] && s[i - 1] <= '9' && 'a' <= s[i] && s[i] <= 'z')) thing = false;
            if ('0' <= s[i] && s[i] <= '9' && 'a' <= s[i - 1] && s[i - 1] <= 'z') thing = false;
        }
        cout << (thing ? "YES\n" : "NO\n");
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
