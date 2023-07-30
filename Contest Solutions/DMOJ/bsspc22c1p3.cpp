#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c, ans = 0, grid[1002][1002], dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        grid[r][c] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int temp = 0;
            for (int d = 0; d < 8; d++) if (grid[i + dr[d]][j + dc[d]]) temp++;
            if (grid[i][j] == 0 && temp > 2) ans++;
        }
    }
    cout << ans << "\n";
}
