#include <bits/stdc++.h>
using namespace std;

int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << "1 1\n1 2\n";
        if (n > 2) {
            cout << "3 1\n";
            for (int i = 4; i <= n; i++) cout << i << " " << i << "\n";
        }
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
