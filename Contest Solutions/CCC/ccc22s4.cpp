#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, c, p;
ll a[2000005], psa[2000005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> c;
    ll ans = (ll)n * (n - 1) * (n - 2)/6;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        ++a[p];
        ++a[p + c];
    }
    for (int i = 1; i <= 2 * c; i++) psa[i] = a[i] + psa[i - 1];
    for (int i = c; i < 2 * c; i++) {
        int idx = i - c/2;
        if (c%2 == 0) {
            ++idx;
            ans -= (psa[i - 1] - psa[idx - 1]) * a[i] * a[idx - 1];
            if (i < c + c/2) ans -= a[i] * (a[i] - 1)/2 * a[idx - 1] + a[i] * a[idx - 1] * (a[idx - 1] - 1)/2;
        }
        ll tmp = psa[i - 1] - psa[idx - 1];
        ans -= tmp * (tmp - 1)/2 * a[i] + tmp * a[i] * (a[i] - 1)/2 + a[i] * (a[i] - 1) * (a[i] - 2)/6;
    }
    cout << ans << "\n";
    return 0;
}