#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t;
ll n;
void solve() {
    cin >> n;
    if (n < 7) {
        cout << "-1\n";
        return;
    }
    if (__builtin_popcountll(n) == 1) {
        cout << ((n >> 1) | (n >> 2) | (n >> 3)) << "\n";
        return;
    }
    if (__builtin_popcountll(n) == 2) {
        ll x = (n & -n);
        n ^= x;
        if (x > 2) cout << (n | (x >> 1) | (x >> 2)) << "\n";
        else cout << ((n >> 1) | (n >> 2) | (n >> 3)) << "\n";
        return;
    }
    while (__builtin_popcountll(n) > 3) n -= (n & -n);
    cout << n << "\n";
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