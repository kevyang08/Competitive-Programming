#include <bits/stdc++.h>
using namespace std;

int n, q, s, t, l, r, x;
long long a[200005], d[200005], ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q >> s >> t >> a[0];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        ans -= d[i] * (d[i] > 0 ? s : t);
    }
    while (q--) {
        d[n + 1] = 0;
        cin >> l >> r >> x;
        ans += d[l] * (d[l] > 0 ? s : t);
        d[l] += x;
        ans -= d[l] * (d[l] > 0 ? s : t);
        if (r < n) {
            ans += d[r + 1] * (d[r + 1] > 0 ? s : t);
            d[r + 1] -= x;
            ans -= d[r + 1] * (d[r + 1] > 0 ? s : t);
        }
        cout << ans << "\n";
    }
    return 0;
}
