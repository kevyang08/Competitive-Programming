#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n;
ll res;
void solve() {
    cin >> n;
    cout << "? 1 " << n << endl;
    cin >> res;
    int l = 1, r = n;
    while (l < r) {
        int lo = l, hi = r;
        ll bruh = res/2;
        while (lo < hi) {
            int m = (lo + hi + 1)/2;
            cout << "? " << l << " " << m << endl;
            cin >> res;
            if (res > bruh) hi = m - 1;
            else lo = m;
        }
        res = bruh;
        if (lo - l + 1 > r - lo) l = lo + 1;
        else r = lo;
    }
    cout << "! " << res << endl;
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