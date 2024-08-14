#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[1001][1001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cnt += (a[i][j] != a[n - i + 1][n - j + 1]);
        // cout << cnt << " " << cnt/2%2 << " bruh\n";
        assert(cnt%2 == 0);
        cout << (cnt/2 <= k && (cnt/2%2 == k%2 || n%2) ? "YES\n" : "NO\n");
    }
    return 0;
}