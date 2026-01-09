#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, x, y, p;
string s;
void solve() {
    cin >> n >> x >> y >> s;
    bool ans = true, aa = false, bb = false;
    ll rem = 0, bruh = 0;
    for (int i = 0; i < n; i++) {
        cin >> p;
        int tmp = p/2 + 1;
        if (s[i] == '0') x -= tmp, aa = true;
        else y -= tmp, bb = true;
        if (x < 0 || y < 0) ans = false;
        rem += p - tmp;
        bruh += (p & 1) ^ 1;
    }
    bruh += rem;
    if (!bb && y - x > bruh) ans = false;
    if (!aa && x - y > bruh) ans = false;
    if (x + y < rem) ans = false;
    cout << (ans ? "YES\n" : "NO\n");
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