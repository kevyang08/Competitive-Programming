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
        int ans = 0x3f3f3f3f;
        if (n < 3) {
            cout << stoi(s) << "\n";
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            int res = stoi(s.substr(i, 2));
            if (!res) {
                ans = 0;
                break;
            }
            else if (res == 1) --res;
            for (int j = 0; j < n; j++) {
                if (j == i || j == i + 1) continue;
                if (s[j] == '0') {
                    ans = 0;
                    break;
                }
                else if (s[j] > '1') res += s[j] - '0';
            }
            ans = min(ans, max(res, 1));
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