#include <bits/stdc++.h>
using namespace std;

int t, n, a, m, l, r;
char c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            mx = max(mx, a);
        }
        while (m--) {
            cin >> c >> l >> r;
            if (mx < l || mx > r) {
                cout << mx << " ";
                continue;
            }
            if (c == '-') --mx;
            else ++mx;
            cout << mx << " ";
        }
        cout << "\n";
    }
    return 0;
}