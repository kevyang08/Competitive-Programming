#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, q;
ll a[1000001], l, r;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        while (q--) {
            cin >> l >> r;
            ll lo = (l - 1)/n, hi = (r - 1)/n, res = 0;
            if (lo != hi) {
                res = a[n] * (hi - lo - 1);
                int s = (l - 1)%n + 1 + lo, e = (r - 1)%n + 1 + hi;
                if (s > n) res += a[lo] - a[s%n - 1];
                else res += a[n] - a[s - 1] + a[lo];
                if (e <= n) res += a[e] - a[hi];
                else res += a[n] - a[hi] + a[e%n];
            }
            else {
                int s = (l - 1)%n + 1 + lo, e = (r - 1)%n + 1 + lo;
                if (e <= n) res = a[e] - a[s - 1];
                else if (s > n) res = a[e%n] - a[s%n - 1];
                else res = a[n] - a[s - 1] + a[e%n];
            }
            cout << res << "\n";
        }
    }
    return 0;
}