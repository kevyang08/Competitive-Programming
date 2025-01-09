#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// bruh
/*
10 6
28

20 7
14 + 26 + 40 = 80
40 + 26 + 12 = 78

7 2
4 + 8 + 10 + 14 = 36
2 + 6 + 10 + 14 = 32
*/

ll n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    if (k >= n) cout << 2 * n << "\n";
    else {
        ll tmp = n%k, x = n/k;
        if (!tmp) {
            cout << k * x * (x + 1) << "\n";
        }
        // else if (tmp <= n/k) {
        //     for (int i = 1; i <= n/k + (n%k ? 1 : 0); i++) {
        //         if (i <= tmp) ans += 2 * i * k;
        //         else ans += 2 * i * (k - 1);
        //     }
        //     cout << ans << "\n";
        // }
        else {
            cout << k * x * (x + 1) + 2 * tmp * x + 2 * tmp << "\n";
        }
        // cout << ans << "\n";
    }
    return 0;
}