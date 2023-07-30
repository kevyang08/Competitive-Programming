#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k, q, t[5000], l[5000], b[5000], r[5000], y, x;
    cin >> n >> k >> q;
    for (int i = 0; i < k; i++) cin >> t[i] >> l[i] >> b[i] >> r[i];
    while (q--) {
        cin >> y >> x;
        for (int i = k - 1; i >= 0; i--) {
            if (y >= t[i] && y <= b[i] && x >= l[i] && x <= r[i]) {
                int temp = y;
                y = t[i] + (r[i] - x);
                x = r[i] - (b[i] - temp);
            }
        }
        cout << (y - 1) * (long long)n + x << "\n";
    }
    return 0;
}
