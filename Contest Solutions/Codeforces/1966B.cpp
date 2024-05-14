#include <bits/stdc++.h>
using namespace std;

int t, n, m;
string grid[500];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> grid[i];
        bool ans = false;
        if (grid[0][0] == grid[n - 1][m - 1] || grid[0][m - 1] == grid[n - 1][0]) ans = true;
        for (int i = 0; i < m; i++) if (grid[n - 1][i] == grid[0][0] && grid[0][0] == grid[0][m - 1]) ans = true;
        for (int i = 0; i < m; i++) if (grid[0][i] == grid[n - 1][0] && grid[n - 1][0] == grid[n - 1][m - 1]) ans = true;
        for (int i = 0; i < n; i++) if (grid[i][m - 1] == grid[0][0] && grid[0][0] == grid[n - 1][0]) ans = true;
        for (int i = 0; i < n; i++) if (grid[i][0] == grid[0][m - 1] && grid[0][m - 1] == grid[n - 1][m - 1]) ans = true;
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
