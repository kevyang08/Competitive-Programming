#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, p, s;
void solve() {
    cin >> p >> s;
    int g = __gcd(p, s);
    p /= g, s /= g;
    if (p%2) p *= 2, s *= 2;
    int pp = p, ss = s;
    while (ss <= 50000) {
        int c = pp/2 - 1, l = c/2 + 1, h = c/2 + c%2;
        if (c > ss || (ll)l * h < ss) {
            pp += p, ss += s;
            continue;
        }
        cout << ss << "\n";
        for (int i = 0; i < h; i++) cout << "0 " << i << "\n";
        for (int i = 0, j = 0; i < ss - h; j++) {
            if (j%l == 0) continue;
            ++i;
            cout << j%l << " " << j/l << "\n";
        }
        return;
    }
    cout << "-1\n";
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