#include <bits/stdc++.h>
using namespace std;

int n, m, l, ans = 0, dr[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dc[8] = {0, -1, 0, 1, 1, -1, -1, 1};
string s;
char a[100][100];
void check(int r, int c, int d1, int d2, int idx) {
    for (int i = 0; i < l; i++) {
        if (r < 0 || r >= n || c < 0 || c >= m || a[r][c] != s[i]) return;
        if (i < idx) {
            r += dr[d1];
            c += dc[d1];
        }
        else {
            r += dr[d2];
            c += dc[d2];
        }
    }
    ans++;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> s >> n >> m;
    l = s.size();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                for (int idx = 1; idx < l; idx++) {
                    check(i, j, k, (k + 1)%4, idx);
                    check(i, j, k + 4, (k + 1)%4 + 4, idx);
                    if (idx == l - 1) continue;
                    check(i, j, k, (k + 3)%4, idx);
                    check(i, j, k + 4, (k + 3)%4 + 4, idx);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
