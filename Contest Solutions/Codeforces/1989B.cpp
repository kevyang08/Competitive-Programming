#include <bits/stdc++.h>
using namespace std;

int t;
string a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int ans = 0;
        for (int i = 0; i < b.length(); i++) {
            int idx = i;
            for (int j = 0; j < a.length(); j++) if (idx < b.length() && a[j] == b[idx]) ++idx;
            ans = max(ans, idx - i);
        }
        cout << a.length() + b.length() - ans << "\n";
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