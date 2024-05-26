#include <bits/stdc++.h>
using namespace std;

int t, thing[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        thing[0] = thing[1] = 1;
        bool ans = true;
        int idx = 0;
        string s;
        cin >> s;
        for (char c : s) {
            if (c == '+') {
                ++idx;
                if (idx > 1) thing[idx] = thing[idx - 1] == 0 ? 0 : -1;
            }
            else if (c == '-') {
                --idx;
                if (idx > 1 && thing[idx + 1] == 1) thing[idx] = thing[idx + 1];
            }
            else {
                if (thing[idx] != -1 && thing[idx] != c - '0') ans = false;
                if (thing[idx] == -1) thing[idx] = c - '0';
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
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
