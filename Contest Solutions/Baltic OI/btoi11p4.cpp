#include <bits/stdc++.h>
using namespace std;

int n, m, sr, sc, vr, vc, er, ec, dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
string grid[700];
bool visy[700][700], visv[700][700], seen[700][700];
void bruh(int r, int c, int d) {
    for (; r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != 'I'; r += dr[d], c += dc[d]) seen[r][c] = true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'Y') {
                sr = i;
                sc = j;
            }
            else if (grid[i][j] == 'V') {
                vr = i;
                vc = j;
            }
            else if (grid[i][j] == 'T') {
                er = i;
                ec = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) bruh(vr, vc, i);
    queue<int> qr, qc, qt;
    qr.push(vr); qc.push(vc); qt.push(1);
    qr.push(sr); qc.push(sc); qt.push(0);
    while (!qr.empty()) {
        int cr = qr.front(), cc = qc.front(), ct = qt.front();
        // cout << cr << " " << cc << " " << ct << "\n";
        qr.pop(); qc.pop(); qt.pop();
        if (ct) {
            for (int k = 0; k < 4; k++) {
                if (cr + dr[k] >= 0 && cr + dr[k] < n && cc + dc[k] >= 0 && cc + dc[k] < m && grid[cr + dr[k]][cc + dc[k]] != 'I' && !visv[cr + dr[k]][cc + dc[k]]) {
                    visv[cr + dr[k]][cc + dc[k]] = true;
                    qr.push(cr + dr[k]);
                    qc.push(cc + dc[k]);
                    qt.push(1);
                    if (k%2 == 0) {
                        bruh(cr + dr[k], cc + dc[k], 1);
                        bruh(cr + dr[k], cc + dc[k], 3);
                    }
                    else {
                        bruh(cr + dr[k], cc + dc[k], 0);
                        bruh(cr + dr[k], cc + dc[k], 2);
                    }
                }
            }
        }
        else {
            for (int k = 0; k < 4; k++) {
                if (cr + dr[k] >= 0 && cr + dr[k] < n && cc + dc[k] >= 0 && cc + dc[k] < m && grid[cr + dr[k]][cc + dc[k]] != 'I' && !visv[cr + dr[k]][cc + dc[k]] && !visy[cr + dr[k]][cc + dc[k]] && !seen[cr + dr[k]][cc + dc[k]]) {
                    visy[cr + dr[k]][cc + dc[k]] = true;
                    qr.push(cr + dr[k]);
                    qc.push(cc + dc[k]);
                    qt.push(0);
                }
            }
        }
    }
    cout << (visy[er][ec] ? "YES\n" : "NO\n");
}
