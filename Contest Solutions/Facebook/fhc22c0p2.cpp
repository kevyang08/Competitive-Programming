#include <bits/stdc++.h>
using namespace std;

int t, r, c, prvr[3000][3000], prvc[3000][3000], dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
char grid[3000][3000];
bool vis[3000][3000];
queue<pair<int, int>> q;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("second_friend_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                prvr[i][j] = prvc[i][j] = -1;
                cin >> grid[i][j];
                vis[i][j] = false;
                if (grid[i][j] == '^') {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                if (p.first + dr[k] >= 0 && p.first + dr[k] < r && p.second + dc[k] >= 0 && p.second + dc[k] < c && grid[p.first + dr[k]][p.second + dc[k]] == '.') {
                    if (vis[p.first + dr[k]][p.second + dc[k]]) {
                        int i = p.first + dr[k], j = p.second + dc[k];
                        while (grid[i][j] == '.') {
                            grid[i][j] = '^';
                            if (i != prvr[i][j]) i = prvr[i][j];
                            else j = prvc[i][j];
                        }
                        i = p.first;
                        j = p.second;
                        while (grid[i][j] == '.') {
                            grid[i][j] = '^';
                            if (i != prvr[i][j]) i = prvr[i][j];
                            else j = prvc[i][j];
                        }
                    }
                    else {
                        q.push({p.first + dr[k], p.second + dc[k]});
                        prvr[p.first + dr[k]][p.second + dc[k]] = p.first;
                        prvc[p.first + dr[k]][p.second + dc[k]] = p.second;
                        vis[p.first + dr[k]][p.second + dc[k]] = true;
                    }
                }
            }
        }
        bool thing = true;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] != '^') continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++) if (i + dr[k] >= 0 && i + dr[k] < r && j + dc[k] >= 0 && j + dc[k] < c && grid[i + dr[k]][j + dc[k]] == '^') cnt++;
                if (cnt < 2) thing = false;
            }
        }
        if (thing) {
            printf("Case #%d: Possible\n", bruh);
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    printf("%c", grid[i][j]);
                }
                printf("\n");
            }
        }
        else printf("Case #%d: Impossible\n", bruh);
    }
    return 0;
}
