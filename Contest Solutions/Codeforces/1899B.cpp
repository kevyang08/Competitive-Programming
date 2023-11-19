#include <bits/stdc++.h>
using namespace std;
 
int t, n;
long long a[150001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) a[i] += a[i - 1];
        for (int i = 1; i < n; i++) {
            if (n%i) continue;
            long long mn = 0x3f3f3f3f3f3f3f3f, mx = 0;
            for (int j = i; j <= n; j += i) {
                mn = min(mn, a[j] - a[j - i]);
                mx = max(mx, a[j] - a[j - i]);
            }
            ans = max(ans, mx - mn);
        }
        cout << ans << "\n";
    }
    return 0;
}
