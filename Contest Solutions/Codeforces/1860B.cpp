#include <bits/stdc++.h>
using namespace std;
 
int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        long long m, k, a, b, ans = 0;
        cin >> m >> k >> a >> b;
        if (b * k <= m) m -= b * k;
        else m %= k;
        m = max(m - a, 0LL);
        if (m > 0) {
            if (m >= k) {
                ans = m/k;
                m %= k;
            }
            if (m && m + a >= k) {
                ans++;
                m = 0;
            }
            else ans += m;
        }
        cout << ans << "\n";
    }
    return 0;
}
