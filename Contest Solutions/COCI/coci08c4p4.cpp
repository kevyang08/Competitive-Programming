#include <bits/stdc++.h>
using namespace std;

int n, arr[513][513], psa[513][513], ans[513][513];
int bruh(int r1, int c1, int r2, int c2) {
    if (r1 == r2) {
        ans[r1][c1] = arr[r1][c1];
        return 0;
    }
    int rm = (r1 + r2)/2, cm = (c1 + c2)/2, r[4][2] = {{r1, rm}, {r1, rm}, {rm + 1, r2}, {rm + 1, r2}}, c[4][2] = {{c1, cm}, {cm + 1, c2}, {c1, cm}, {cm + 1, c2}}, diff[4] = {0, 0, 0, 0}, res[16], mn = 1;
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 4; i++) diff[i] = bruh(r[i][0], c[i][0], r[i][1], c[i][1]);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) continue;
            res[i * 4 + j] = diff[0] + diff[1] + diff[2] + diff[3] - diff[i] - diff[j] + psa[r[i][1]][c[i][1]] - psa[r[i][0] - 1][c[i][1]] - psa[r[i][1]][c[i][0] - 1] + psa[r[i][0] - 1][c[i][0] - 1] + (r[j][1] - r[j][0] + 1) * (r[j][1] - r[j][0] + 1) - (psa[r[j][1]][c[j][1]] - psa[r[j][0] - 1][c[j][1]] - psa[r[j][1]][c[j][0] - 1] + psa[r[j][0] - 1][c[j][0] - 1]);
            if (res[i * 4 + j] < res[mn]) mn = i * 4 + j;
        }
    }
    for (int i = r[mn/4][0]; i <= r[mn/4][1]; i++) for (int j = c[mn/4][0]; j <= c[mn/4][1]; j++) ans[i][j] = 0;
    for (int i = r[mn%4][0]; i <= r[mn%4][1]; i++) for (int j = c[mn%4][0]; j <= c[mn%4][1]; j++) ans[i][j] = 1;
    return res[mn];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
            arr[i][j] = s[j - 1] - '0';
            if (arr[i][j]) psa[i][j]++;
        }
    }
    cout << bruh(1, 1, n, n) << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << ans[i][j];
        cout << "\n";
    }
}
