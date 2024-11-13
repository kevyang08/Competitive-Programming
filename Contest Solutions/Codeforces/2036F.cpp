#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
find min mn such that mn >= l && mn%2^i=k
find max mx such that mx <= r && mx%2^i=k
*/

int t;
ll l, r, i, k;
ll thing(ll n) {
    if (n%4 == 0) return n;
    if (n%4 == 1) return 1;
    if (n%4 == 2) return n + 1;
    return 0;
}
ll bs1(ll n, ll i, ll k) {
    ll lo = 0, hi = (INFL >> i);
    while (lo < hi) {
        ll m = (lo + hi)/2;
        if (((m << i) | k) >= n) hi = m;
        else lo = m + 1;
    }
    return lo;
}
ll bs2(ll n, ll i, ll k) {
    ll lo = 0, hi = (INFL >> i);
    while (lo < hi) {
        ll m = (lo + hi + 1)/2;
        if (((m << i) | k) <= n) lo = m;
        else hi = m - 1;
    }
    return hi;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> l >> r >> i >> k;
        ll ans = thing(r) ^ thing(l - 1), mn = bs1(l, i, k);
        if (((mn << i) | k) > r) {
            cout << ans << "\n";
            continue;
        }
        ll mx = bs2(r, i, k);
        if ((mx - mn + 1)%2) {
            for (int j = 0; j < 31; j++) {
                int c = (1 << j);
                if (!(k & c)) continue;
                ans ^= c;
            }
        }
        ans ^= ((thing(mx) ^ thing(mn - 1)) << i);
        cout << ans << "\n";
    }
    return 0;
}