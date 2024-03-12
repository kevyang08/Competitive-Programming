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
        int cnt[2] = {0, 0};
        cin >> n >> s;
        for (int i = 0; i + 2 < s.length(); i++) if (s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") cnt[0]++;
        for (int i = 0; i + 4 < s.length(); i++) {
            if (s.substr(i, 5) == "mapie") {
                cnt[1]++;
                i += 4;
            }
        }
        cout << cnt[0] - cnt[1] << "\n";
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
