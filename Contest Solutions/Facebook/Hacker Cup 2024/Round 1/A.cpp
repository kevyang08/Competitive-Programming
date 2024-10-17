#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double eps = 1e-6;

int t, n, a[1000001], b[1000001];
// bool check(double dt) {
//     cout << dt << " bruh\n";

//     for (int i = 1; i <= n; i++) if (i/dt + eps < a[i] || i/dt - eps > b[i]) return false;

//     cout << dt << " passes\n";

//     return true;
// }
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        double l = (double)n/b[n], r = INFINITY;
        for (int i = 1; i <= n; i++) {
            // if (i/l - eps > b[i] || i/r + eps < a[i]) {
            //     l = -1;
            //     break;
            // }
            l = max(l, (double)i/b[i]);
            r = min(r, (double)i/a[i]);
        }
        // cout << l << " " << r << " bruh\n";

        cout << setprecision(6) << (l > r ? -1 : l) << "\n";
    }
    return 0;
}