#include <bits/stdc++.h>
using namespace std;

int r, c, m, dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1}, mnr[4], mnc[4], mxr[4], mxc[4], er[4], ec[4];
string grid[375];
char s[30000], ans[375][80];
set<pair<int, int>> vis[4];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(ans, '.', sizeof(ans));
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> grid[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> s[i];
    for (int k = 0; k < 4; k++) {
        mnr[k] = mnc[k] = 0x3f3f3f3f;
        vis[k].insert({0, 0});
        int idx = 0, d = k, cr = 0, cc = 0;
        while (idx < m) {
            if (s[idx] == 'F') {
                cr += dr[d];
                cc += dc[d];
            }
            else if (s[idx] == 'L') d++;
            else d--;
            if (d < 0) d += 4;
            if (d > 3) d -= 4;
            vis[k].insert({cr, cc});
            mnr[k] = min(mnr[k], cr);
            mnc[k] = min(mnc[k], cc);
            mxr[k] = max(mxr[k], cr);
            mxc[k] = max(mxc[k], cc);
            idx++;
        }
        er[k] = cr;
        ec[k] = cc;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'X') {
                ans[i][j] = 'X';
                continue;
            }
            for (int k = 0; k < 4; k++) {
                if (mnr[k] + i < 0 || mxr[k] + i >= r || mnc[k] + j < 0 || mxc[k] + j >= c) continue;
                bool thing = true;
                for (pair p : vis[k]) if (grid[p.first + i][p.second + j] == 'X') thing = false;
                if (thing) ans[er[k] + i][ec[k] + j] = '*';
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}
