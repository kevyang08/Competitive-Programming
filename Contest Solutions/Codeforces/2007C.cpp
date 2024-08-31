#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c[100001], m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++) cin >> c[i];
        m = __gcd(a, b);
        set<int> st;
        for (int i = 1; i <= n; i++) st.insert(c[i]%m);
        int mx = *st.rbegin() + m, mn = 0x3f3f3f3f;
        while (*st.rbegin() != mx) {
            mn = min(mn, *st.rbegin() - *st.begin());
            st.insert(*st.begin() + m);
            st.erase(st.begin());
        }
        cout << mn << "\n";
    }
    return 0;
}