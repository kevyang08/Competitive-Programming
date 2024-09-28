#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
ll k, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        ll s = 0, mx = 0;
        int ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a;
            s += a;
            mx = max(mx, a);
        }
        for (int i = 1; i <= n; i++) {
            ll tmp = (s + k)/i * i;
            if (tmp < s) continue;
            if (tmp/i >= mx) ans = max(ans, i);
        }
        cout << ans << "\n";
    }
    return 0;
}