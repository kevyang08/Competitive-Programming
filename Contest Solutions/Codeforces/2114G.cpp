#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, a[100005];
ll pf[100005], sf[100005];
void solve() {
    cin >> n >> k;
    cin >> a[1];
    pf[1] = (1 << __builtin_ctz(a[1]));
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        int tz = __builtin_ctz(a[i]), ptz = __builtin_ctz(a[i - 1]);
        pf[i] = pf[i - 1] + (1 << tz);
        if (tz < ptz && a[i] == (a[i - 1] >> (ptz - tz))) pf[i] -= (1 << (tz + 1)) - 1;
    }
    if (pf[n] >= k) {
        cout << "YES\n";
        return;
    }
    sf[n] = (1 << __builtin_ctz(a[n]));
    for (int i = n - 1; i > 0; i--) {
        int tz = __builtin_ctz(a[i]), ntz = __builtin_ctz(a[i + 1]);
        sf[i] = sf[i + 1] + (1 << tz);
        if (tz < ntz && a[i] == (a[i + 1] >> (ntz - tz))) sf[i] -= (1 << (tz + 1)) - 1;
        if (pf[i] + sf[i] - (1 << tz) >= k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}