#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, q, a, l, r, ans[250005], thing[250005];
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ans[i] = ans[i - 1];
        thing[i] = thing[i - 1];
        if (__builtin_popcount(a) > 1) ++ans[i];
        if ((a & 1) && __builtin_popcount(a) == 2) ++thing[i];
        while (a >>= 1) ++ans[i];
    }
    while (q--) {
        cin >> l >> r;
        cout << ans[r] - ans[l - 1] - (thing[r] - thing[l - 1]) + (thing[r] - thing[l - 1])/2 << "\n";
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