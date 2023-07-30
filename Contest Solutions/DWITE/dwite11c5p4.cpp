#include <bits/stdc++.h>
using namespace std;

int t = 5, n, m, grid[20][20], res[20][20], ans = 0, dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    while (t--) {
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                res[i][j] = 0;
            }
        }
        for (int h = 50; h > 0; h--) {
            queue<pair<int, int>> q;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] < h && res[i][j] == 0) res[i][j] = h;
                    if (res[i][j] && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) q.push({i, j});
                }
            }
            while (!q.empty()) {
                pair p = q.front(); q.pop();
                res[p.first][p.second] = 0;
                for (int k = 0; k < 4; k++) {
                    if (p.first + dr[k] < n && p.first + dr[k] >= 0 && p.second + dc[k] < m && p.second + dc[k] >= 0 && grid[p.first + dr[k]][p.second + dc[k]] < h && res[p.first + dr[k]][p.second + dc[k]]) {
                        res[p.first + dr[k]][p.second + dc[k]] = 0;
                        q.push({p.first + dr[k], p.second + dc[k]});
                    }
                }
            }
        }
        for (int i = 1; i < n - 1; i++) for (int j = 1; j < m - 1; j++) if (res[i][j]) ans += res[i][j] - grid[i][j];
        cout << ans << "\n";
    }
    return 0;
}
