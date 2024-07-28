#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
ll k, a[200001], b[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll ans = 0, l = 0, r = 1e9;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        while (l <= r) {
            ll m = (l + r)/2, c = 0, res = 0, bruh = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == m) ++bruh;
                if (a[i] <= m) continue;
                ll temp = (a[i] - m)/b[i] + 1;
                if (a[i] - b[i] * (temp - 1) == m) --temp, ++bruh;
                if (temp) res = res + (a[i] * temp - (temp - 1) * temp/2 * b[i]);
                c += temp;
            }
            if (c <= k) {
                ans = max(ans, res + min(k - c, bruh) * m);
                r = m - 1;
            }
            else l = m + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}