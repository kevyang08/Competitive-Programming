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
        int b = 0;
        cin >> s;
        n = stoi(s);
        for (int i = 1; n > 9; i *= 10) {
            b += n%10 * i;
            n /= 10;
            if (b > n && to_string(n) + to_string(b) == s) break;
        }
        if (b <= n || to_string(n) + to_string(b) != s) cout << "-1\n";
        else cout << n << " " << b << "\n";
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