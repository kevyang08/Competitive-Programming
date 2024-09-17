#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, m, q, b, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        set<int> st;
        cin >> n >> m >> q;
        while (m--) {
            cin >> b;
            st.insert(b);
        }
        while (q--) {
            cin >> a;
            auto it = st.lower_bound(a);
            ll l = INT_MIN, r = INT_MAX;
            if (it != st.end()) r = *it;
            if (it == st.end() || *it > *st.begin()) l = *--it;
            if (l == INT_MIN) cout << r - 1 << "\n";
            else if (r == INT_MAX) cout << n - l << "\n";
            else cout << (r - l)/2 << "\n";
        }
    }
    return 0;
}