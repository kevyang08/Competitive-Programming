#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, z, dist[101][101][101], idx[101][101][101], dx[6] = {-1, 1, 0, 0, 0, 0}, dy[6] = {0, 0, -1, 1, 0, 0}, dz[6] = {0, 0, 0, 0, -1, 1};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    queue<pair<tuple<int, int, int>, int>> q;
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        q.push({{x, y, z}, i});
        idx[x][y][z] = i, dist[x][y][z] = 0;
    }
    while (!q.empty()) {
        auto [fi, i] = q.front(); q.pop();
        auto [a, b, c] = fi;
        if (idx[a][b][c] != i) continue;
        for (int k = 0; k < 6; k++) {
            if (a + dx[k] < 0 || a + dx[k] > 100 || b + dy[k] < 0 || b + dy[k] > 100 || c + dz[k] < 0 || c + dz[k] > 100) continue;
            auto j = idx[a + dx[k]][b + dy[k]][c + dz[k]];
            if (dist[a + dx[k]][b + dy[k]][c + dz[k]] < dist[a][b][c] + 1 || dist[a + dx[k]][b + dy[k]][c + dz[k]] == dist[a][b][c] + 1 && j <= i) continue;
            q.push({{a + dx[k], b + dy[k], c + dz[k]}, i});
            idx[a + dx[k]][b + dy[k]][c + dz[k]] = i;
            dist[a + dx[k]][b + dy[k]][c + dz[k]] = dist[a][b][c] + 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        cout << idx[x][y][z] << "\n";
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