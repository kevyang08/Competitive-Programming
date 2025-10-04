#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, q, a[250005], l, r;
void solve() {
    set<int> st;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1 && a[i] == a[i - 1]) st.insert(i - 1);
    }
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    while (q--) {
        cin >> l >> r;
        if ((r - l + 1)%3 || (a[r] - a[l - 1])%3) cout << "-1\n";
        else {
            if (st.lower_bound(l) != st.end() && *st.lower_bound(l) < r) cout << (r - l + 1)/3 << "\n";
            else cout << (r - l + 1)/3 + 1 << "\n";
        }
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