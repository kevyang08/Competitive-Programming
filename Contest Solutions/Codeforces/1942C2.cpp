#include <bits/stdc++.h>
using namespace std;

int t, n, x, y;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        int ans = 0;
        vector<int> p(x), v;
        for (int i = 0; i < x; i++) cin >> p[i];
        sort(p.begin(), p.end());
        for (int i = 1; i < x; i++) if (p[i] - p[i - 1] > 1) v.push_back(p[i] - p[i - 1]);
        if (p[0] + n - p[x - 1] > 1) v.push_back(p[0] + n - p[x - 1]);
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
            return a%2 != b%2 ? a%2 < b%2 : a < b;
        });
        for (const auto &i : v) {
            if (y >= (i - 1)/2 && i%2 == 0) ++ans;
            ans += min(y, (i - 1)/2);
            if (i == 2) continue;
            x += min(y, (i - 1)/2);
            y = max(0, y - (i - 1)/2);
            if (!y) break;
        }
        cout << ans + x - 2 << "\n";
    }
    return 0;
}