#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, k, a[200005];
ll psa[200005], ppsa[200005];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) {
            psa[i] = (k - a[i] + a[i - 1]) + psa[i - 1];
            ppsa[i] = psa[i] + ppsa[i - 1];
        }
    }
    cout << 0;
    for (int i = 2; i < n; i++) {
        cout << ' ';
        if (k >= a[i + 1] - a[i - 1]) {
            cout << 0;
            continue;
        }
        int l = i + 1, r = n;
        while (l < r) {
            int m = (l + r + 1)/2;
            if (a[i + 1] - a[i - 1] - k > psa[m] - psa[i + 1]) l = m;
            else r = m - 1;
        }

        // cout << "\n";
        // cout << i << " " << l << " debug\n"; // debug
        // cout << a[i + 1] - a[i - 1] - k << " bruh\n";
        // cout << psa[l] - psa[i + 1] << " wtf\n";

        ll ans = a[i + 1] - a[i - 1] - k;
        if (l > i + 1) {
            // cout << (ll)(l - i - 1) * (a[i + 1] - a[i - 1] - k) << " " << ppsa[l] - ppsa[i + 1] << " here\n";

            ans += (ll)(l - i - 1) * (a[i + 1] - a[i - 1] - k) - ppsa[l] + ppsa[i + 1] + (ll)(l - i - 1) * (psa[i + 1]);
        }
        cout << ans;
    }
    cout << " 0\n";
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