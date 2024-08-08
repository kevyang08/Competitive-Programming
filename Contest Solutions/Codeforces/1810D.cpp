#include <bits/stdc++.h>
using namespace std;

int t;
long long q, op, a, b, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long lh = 1, rh = 1e18;
        cin >> q;
        while (q--) {
            cin >> op >> a >> b;
            if (op == 1) {
                cin >> n;
                long long lo = (n > 1 ? a + 1 + (n - 2) * (a - b) : 1), hi = (n > 1 ? a + (n - 1) * (a - b) : a);
                if (lo > rh || hi < lh) cout << "0 ";
                else {
                    cout << "1 ";
                    lh = max(lo, lh), rh = min(hi, rh);
                }
            }
            else cout << ((long long)ceil((double)max(lh - a, 0LL)/(a - b)) == (long long)ceil((double)max(rh - a, 0LL)/(a - b)) ? (long long)ceil((double)max(lh - a, 0LL)/(a - b)) + 1 : -1) << " ";
        }
        cout << "\n";
    }
    return 0;
}