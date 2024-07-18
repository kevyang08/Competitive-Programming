#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[20][20], ans[20][20];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                ans[i][j] = (a[i][j] + 1)%(n * m);
                if (!ans[i][j]) ans[i][j] = n * m;
            }
        }
        if (n == 1 && m == 1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cout << ans[i][j] << (j == m ? "\n" : " ");
    }
    return 0;
}