#include <bits/stdc++.h>
using namespace std;
 
int t, n, x, a[55];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) ans = max(ans, a[i] - a[i - 1]);
        cout << max(ans, 2 * x - 2 * a[n]) << "\n";
    }
    return 0;
}
