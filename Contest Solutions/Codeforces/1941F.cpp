#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int mx1 = 0, mx2 = 0, ans = INT_MAX, idx = 0, avg = 0;
        vector<int> d(m + 1), f(k + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i == 1) continue;
            if (a[i] - a[i - 1] >= mx1) {
                idx = i;
                avg = a[i - 1] + (a[i] - a[i - 1])/2;
                mx2 = mx1;
                mx1 = a[i] - a[i - 1];
            }
            else if (a[i] - a[i - 1] > mx2) mx2 = a[i] - a[i - 1];
        }
        for (int i = 1; i <= m; i++) cin >> d[i];
        for (int i = 1; i <= k; i++) cin >> f[i];
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        for (int i = 1, j = k; i <= m; i++) {
            if (i < m && d[i] == d[i + 1]) continue;
            while (j > 1 && d[i] + f[j - 1] >= avg) --j;
            ans = min(ans, max(d[i] + f[j] - a[idx - 1], a[idx] - d[i] - f[j]));
            if (j > 1) ans = min(ans, max(d[i] + f[j - 1] - a[idx - 1], a[idx] - d[i] - f[j - 1]));
        }
        cout << max(min(mx1, ans), mx2) << "\n";
    }
    return 0;
}