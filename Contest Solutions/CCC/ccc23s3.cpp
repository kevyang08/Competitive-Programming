#include <bits/stdc++.h>
using namespace std;

int n, m, r, c;
char ans[2000][2000], bruh[26];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> r >> c;
    for (int i = 0; i < 26; i++) bruh[i] = (char)(i + 'a');
    if (r < n && c < m) {
        if (r < n && m == 1 || c < m && n == 1) cout << "IMPOSSIBLE\n";
        else {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < m; j++) ans[i][j] = 'a';
            }
            for (int j = 0; j < c; j++) {
                for (int i = 0; i < n; i++) ans[i][j] = 'a';
            }
            for (int i = r; i < n; i++) {
                for (int j = c; j < m; j++) {
                    ans[i][j] = bruh[(1 + i + j)%26];
                    if (ans[i][j] == 'a') ans[i][j] = 'g';
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) cout << ans[i][j];
                cout << '\n';
            }
        }
    }
    else if (r == n && c == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << 'a';
            }
            cout << '\n';
        }
    }
    else if (r == n) {
        if (m%2 == 0 && c%2 == 1 || n == 1 && c != m) cout << "IMPOSSIBLE\n";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i < n - 1 || ((c%2 == 1 || m%2 == 0) && j >= (m - c)/2 && j < (m + c)/2 || m%2 == 1 && c%2 == 0 && (j < c/2 || j >= m - c/2))) cout << 'a';
                    else cout << 'b';
                }
                cout << '\n';
            }
        }
    }
    else if (c == m) {
        if (n%2 == 0 && r%2 == 1 || m == 1 && r != n) cout << "IMPOSSIBLE\n";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (j < m - 1 || ((r%2 == 1 || n%2 == 0) && i >= (n - r)/2 && i < (n + r)/2 || n%2 == 1 && r%2 == 0 && (i < r/2 || i >= n - r/2))) cout << 'a';
                    else cout << 'b';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
