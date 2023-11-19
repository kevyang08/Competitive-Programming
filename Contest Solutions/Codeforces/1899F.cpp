#include <bits/stdc++.h>
using namespace std;
 
int t, n, q, d;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        int cur = n - 1;
        for (int i = 2; i <= n; i++) cout << i - 1 << " " << i << "\n";
        while (q--) {
            cin >> d;
            if (d == cur) cout << "-1 -1 -1\n";
            else {
                cout << n << " " << cur << " " << d << "\n";
                cur = d;
            }
        }
    }
    return 0;
}
