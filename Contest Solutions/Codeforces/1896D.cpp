#include <bits/stdc++.h>
using namespace std;

/*
- store indices of first and last 1
    - if some prefix or suffix starting/ending with 1 >= s, always possible
    - else, have to check with remaining twos
*/

int t, n, q, a[100001], x, y, op;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        set<int> st;
        cin >> n >> q;
        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) st.insert(i);
            s += a[i];
        }
        while (q--) {
            cin >> op >> x;
            if (op == 1) cout << (!st.empty() && (s - *st.begin() * 2 + 2 >= x || s - (n - *st.rbegin()) * 2 >= x) || s >= x && s%2 == x%2 ? "YES\n" : "NO\n");
            else {
                cin >> y;
                if (a[x] == 1) st.erase(x);
                if (y == 1) st.insert(x);
                s += y - a[x];
                a[x] = y;
            }
        }
    }
    return 0;
}