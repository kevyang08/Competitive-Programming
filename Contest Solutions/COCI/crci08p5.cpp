#include <bits/stdc++.h>
using namespace std;

int n, r, c, h, num[100][100], pr[100], pn[100], mn[10000], dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
char grid[100][100];
bool vis[100][100];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> grid[i][j];
    cin >> n;
    for (int k = 0; k < n; k++) {
        memset(vis, false, sizeof(vis));
        memset(pn, -1, sizeof(pn));
        int cn = 0;
        vector<pair<int, int>> v;
        cin >> h;
        if (k%2) {for (int i = c - 1; i >= 0; i--) if (grid[r - h][i] == 'x') {grid[r - h][i] = '.'; break;}}
        else {for (int i = 0; i < c; i++) if (grid[r - h][i] == 'x') {grid[r - h][i] = '.'; break;}}
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'x' && !vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    while (!q.empty()) {
                        pair p = q.front(); q.pop();
                        num[p.first][p.second] = cn;
                        for (int d = 0; d < 4; d++) {
                            if (p.first + dr[d] < 0 || p.first + dr[d] >= r || p.second + dc[d] < 0 || p.second + dc[d] >= c || vis[p.first + dr[d]][p.second + dc[d]] || grid[p.first + dr[d]][p.second + dc[d]] != 'x') continue;
                            q.push({p.first + dr[d], p.second + dc[d]});
                            vis[p.first + dr[d]][p.second + dc[d]] = true;
                        }
                    }
                    cn++;
                }
            }
        }
        for (int i = 0; i < cn; i++) mn[i] = 0x3f3f3f3f;
        for (int i = 0; i < c; i++) pr[i] = r; // cuz memset is a useless piece of shit
        for (int i = r - 1; i >= 0; i--) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] != 'x') continue;
                if (num[i][j] != pn[j]) mn[num[i][j]] = min(mn[num[i][j]], pr[j] - i - 1);
                pn[j] = num[i][j];
                pr[j] = i;
            }
        }
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (grid[i][j] == 'x') v.push_back({i + mn[num[i][j]], j});
        memset(grid, '.', sizeof(grid));
        for (pair p : v) grid[p.first][p.second] = 'x';
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << grid[i][j];
        cout << "\n";
    }
    return 0;
}
