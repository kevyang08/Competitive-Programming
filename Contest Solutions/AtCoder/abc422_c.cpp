#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

ll t, a, b, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int l = 0, r = min(a, c);
        while (l < r) {
            ll m = (l + r + 1)/2;
            if (a + b + c - 2 * m >= m) l = m;
            else r = m - 1;
        }
        cout << l << "\n";
    }
    return 0;
}