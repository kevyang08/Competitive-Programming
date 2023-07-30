#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, mx = -1, mp = -1, a[1000], b[3000];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
    for (int i = 0; i < n; i++) {
        int d = 0x3f3f3f3f, l = 0, r = m - 1;
        while (l < r) {
            int m = (l + r + 1)/2;
            if (a[i] >= b[m]) l = m;
            else r = m - 1;
        }
        if (l < m - 1) d = b[l + 1] - a[i];
        d = min(d, a[i] - b[l]);
        if (d > mx) {
            mx = d;
            mp = a[i];
        }
    }
    cout << mp << "\n";
    return 0;
}
