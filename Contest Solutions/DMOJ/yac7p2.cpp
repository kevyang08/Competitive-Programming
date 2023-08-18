#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n == 1 || m == 1) cout << -1 << "\n";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (i == n - 1 && (i%2 ? j == 1 : j == m)) cout << (j == 1 ? "" : " ") << 1;
                    else cout << (j == 1 ? "" : " ") << (i%2 ? (i + 1) * m - j + 1 : i * m + j) + 1;
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
