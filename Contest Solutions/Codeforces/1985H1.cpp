#include <bits/stdc++.h>
using namespace std;

int t, n, m, dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> m;
        vector<string> v(n);
        vector<int> sr(n + 5), sc(m + 5), cr(n + 5), cc(m + 5);
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            for (int j = 0; j < m; j++) {
                cr[i + 1] += v[i][j] == '#';
                cc[j + 1] += v[i][j] == '#';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '.' || vis[i][j]) continue;
                int mnr = i + 1, mxr = mnr, mnc = j + 1, mxc = mnc, sz = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty()) {
                    auto [r, c] = q.front(); q.pop();
                    ++sz;
                    mnr = min(mnr, r + 1), mxr = max(mxr, r + 1), mnc = min(mnc, c + 1), mxc = max(mxc, c + 1);
                    for (int k = 0; k < 4; k++) {
                        if (r + dr[k] < 0 || r + dr[k] >= n || c + dc[k] < 0 || c + dc[k] >= m || v[r + dr[k]][c + dc[k]] == '.' || vis[r + dr[k]][c + dc[k]]) continue;
                        vis[r + dr[k]][c + dc[k]] = true;
                        q.push({r + dr[k], c + dc[k]});
                    }
                }
                for (int k = mnr - 1; k <= mxr + 1; k++) sr[k] += sz;
                for (int k = mnc - 1; k <= mxc + 1; k++) sc[k] += sz;
            }
        }
        for (int i = 1; i <= n; i++) ans = max(ans, sr[i] + m - cr[i]);
        for (int i = 1; i <= m; i++) ans = max(ans, sc[i] + n - cc[i]);
        cout << ans << "\n";
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