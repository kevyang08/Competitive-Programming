#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int s = 0, m = 2 * n;
        for (int i = 1; i <= n; i++) s += (2 * i - 1) * i;
        cout << s << " " << m << "\n";
        for (int i = n; i > 0; i--) {
            cout << 1 << " " << i;
            for (int j = 1; j <= n; j++) cout << " " << j;
            cout << "\n";
            cout << 2 << " " << i;
            for (int j = 1; j <= n; j++) cout << " " << j;
            cout << "\n";
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
