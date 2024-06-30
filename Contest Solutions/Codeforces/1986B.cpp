#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[105][105], dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int mx = 0;
                for (int k = 0; k < 4; k++) {
                    if (i + dr[k] < 1 || i + dr[k] > n || j + dc[k] < 1 || j + dc[k] > m) continue;
                    mx = max(mx, a[i + dr[k]][j + dc[k]]);
                }
                if (a[i][j] > mx) a[i][j] = mx;
                cout << a[i][j] << (j == m ? "\n" : " ");
            }
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