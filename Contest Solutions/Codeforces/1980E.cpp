#include <bits/stdc++.h>
using namespace std;

int t, n, m, b, idr[200001], idc[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> v(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> v[i][j];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> b;
                idr[b] = i, idc[b] = j;
            }
        }
        bool ans = true;
        for (int i = 1; i <= n; i++) {
            int r = idr[v[i][1]];
            for (int j = 2; j <= m; j++) if (idr[v[i][j]] != r) ans = false;
        }
        for (int i = 1; i <= m; i++) {
            int c = idc[v[1][i]];
            for (int j = 2; j <= n; j++) if (idc[v[j][i]] != c) ans = false;
        }
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
