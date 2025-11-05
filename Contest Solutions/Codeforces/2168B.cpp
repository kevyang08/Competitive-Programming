#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, a, res;
string bruh;
void solve() {
    cin >> n;
    if (bruh[0] == 'f') {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (a == 1) ans = 1;
            if (a == n) ans = 0;
        }
        cout << ans << "\n";
        return;
    }
    int l = 1, r = n;
    cin >> a;
    if (a) {
        while (l < r) {
            int m = (l + r + 1)/2;
            cout << "? " << m << " " << n << endl;
            cin >> res;
            if (res < n - 1) r = m - 1;
            else l = m;
        }
    }
    else {
        while (l < r) {
            int m = (l + r)/2;
            cout << "? " << 1 << " " << m << endl;
            cin >> res;
            if (res < n - 1) l = m + 1;
            else r = m;
        }
    }
    cout << "! " << l << endl;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> bruh;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}