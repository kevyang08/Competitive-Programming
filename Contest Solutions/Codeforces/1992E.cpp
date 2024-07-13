#include <bits/stdc++.h>
using namespace std;

int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        vector<pair<int, int>> ans;
        cin >> n;
        long long x = 0;
        for (int i = 1, j = 1; i <= 10000; i++) {
            int k = 1;
            while (k <= x) k *= 10;
            x += n * k;
            if (i == 1) x /= 10;
            while (x > 9 && x > i * n - j && j <= 10000) {
                x /= 10;
                ++j;
            }
            if (j > 10000) break;
            if (x && x == i * n - j) {
                // cout << x << " " << i * n - j << " " << i << " " << j << " bruh\n";
                ans.push_back({i, j});
            }
        }
        cout << ans.size() << "\n";
        for (auto &[a, b] : ans) cout << a << " " << b << "\n";
    }
    return 0;
}