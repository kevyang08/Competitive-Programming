#include <bits/stdc++.h>
using namespace std;

int r, c, a[3], dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1}, ra = 100, ca = 100, rb = 100, cb = 100; 
char grid[100][100];
bool vis[2][100][100];
void dfs(int i, int j, char ch, int d) {
    if (vis[ch - 'A'][i][j]) return;
    if (ch == 'A') {
        if (i < ra || i == ra && j < ca) {
            ra = i;
            ca = j;
        }
    }
    else {
        if (i < rb || i == rb && j < cb) {
            rb = i;
            cb = j;
        }
    }
    vis[ch - 'A'][i][j] = true;
    int t = d;
    while (i + dr[t] < 0 || i + dr[t] >= r || j + dc[t] < 0 || j + dc[t] >= c || grid[i + dr[t]][j + dc[t]] == '.' || t == (d + 2)%4) t = (t + 1)%4;
    dfs(i + dr[t], j + dc[t], ch, t);
}
void bfs(int i, int j, char ch) {
    vis[ch - 'A'][i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (int k = 0; k < 4; k++) 
            if (p.first + dr[k] >= 0 && p.first + dr[k] < r && p.second + dc[k] >= 0 && p.second + dc[k] < c && !vis[ch - 'A'][p.first + dr[k]][p.second + dc[k]]) {
                vis[ch - 'A'][p.first + dr[k]][p.second + dc[k]] = true;
                q.push({p.first + dr[k], p.second + dc[k]});
            }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> grid[i][j];
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        if (grid[i][j] == 'A') dfs(i, j, 'A', 0);
        else if (grid[i][j] == 'B') dfs(i, j, 'B', 0);
    }
    bfs(ra + 1, ca + 1, 'A');
    bfs(rb + 1, cb + 1, 'B');
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != '.') continue;
            if (vis[0][i][j] && vis[1][i][j]) a[2]++;
            else if (vis[0][i][j]) a[0]++;
            else if (vis[1][i][j]) a[1]++;
        }
    }
    cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    return 0;
}
