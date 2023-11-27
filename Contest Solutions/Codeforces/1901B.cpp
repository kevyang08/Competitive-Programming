#include <bits/stdc++.h>
using namespace std;
 
int t, n, c[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) if (c[i] > c[i - 1]) ans += c[i] - c[i - 1];
        cout << ans - 1 << "\n";
    }
    return 0;
}
