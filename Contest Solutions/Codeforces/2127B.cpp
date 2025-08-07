#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, x;
string s;
void solve() {
    cin >> n >> x >> s;
    int l = 0, r = 0, lo = -1, hi = -1;
    for (int i = 0; i < x - 1; i++) if (s[i] == '#') ++l, lo = i + 1;
    for (int i = n - 1; i >= x; i--) if (s[i] == '#') ++r, hi = i + 1;
    if (!l && !r) cout << "1\n";
    else if (!l) cout << min(x, n - hi + 2) << "\n";
    else if (!r) cout << min(n - x + 1, lo + 1) << "\n";
    else {
        if (lo + 1 >= n - hi + 2) cout << min(lo + 1, n - x + 1) << "\n";
        else cout << min(x, n - hi + 2) << "\n";
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