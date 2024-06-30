#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        if (k > 3) cout << "0\n";
        else if (k == 1) cout << "1\n";
        else if (k == 2) {
            if (m <= n) cout << m << "\n";
            else cout << n + m/n - 1 << "\n";
        }
        else {
            if (m <= n) cout << "0\n";
            else cout << m - n - m/n + 1 << "\n";
        }
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