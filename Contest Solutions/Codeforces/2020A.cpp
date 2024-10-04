#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        ll k, n, p, ans = 0;
        cin >> n >> k;
        p = k;
        if (k > 1) while (p * k <= n) p *= k;
        while (n > 0 && p > 1) {
            ans += n/p;
            n -= n/p * p;
            p /= k;
        }
        cout << ans + n << "\n";
    }
    return 0;
}