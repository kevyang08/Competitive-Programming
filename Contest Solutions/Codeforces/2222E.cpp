#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

/*
bruh
*/

int t, n, r, pr;
void solve() {
    cin >> n;
    ll ans = 0;
    cout << 0 << endl;
    cout << "I 0" << endl;
    cin >> pr;
    if (pr == 1) { // k = 1
        // unnecessary to reset pr
        for (ll i = (1LL << (n - 1)); i > 0; i >>= 1) {
            cout << "I " << i << endl;
            cin >> r;
            if (r > pr) ans |= i, pr = r;
        }
        cout << "A 1 " << ans << endl;
    }
    else { // k != 1
        int k = 2;
        for (ll i = (1LL << (n - 1)); i > 0; i >>= 1) {
            cout << "Q " << (ans | i) << endl;
            cin >> r;
            if (r) ans |= i, pr = r;
        }
        ++pr; // for 0
        if (ans == (1LL << n) - 1) {
            cout << "I " << ans - 1 << endl;
            cin >> r;
            if (r > pr) k = 3;
        }
        else {
            cout << "I " << (1LL << n) - 1 << endl;
            cin >> r;
            cout << "Q " << (1LL << n) - 1 << endl;
            cin >> r;
            if (!r) k = 3;
        }
        cout << "A " << k << " " << ans << endl;
    }
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