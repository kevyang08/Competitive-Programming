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
        int c = 0;
        for (int i = 0; i < n/2; i++) c += (s[i] != s[n - i - 1]);
        for (int i = 0; i <= n; i++) cout << (i < c || (i - c)%2 && n%2 == 0 || i > n - c ? 0 : 1);
        cout << "\n";
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