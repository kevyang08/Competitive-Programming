#include <bits/stdc++.h>
using namespace std;
 
int t, n, a, b;
vector<pair<int, int>> v;
bool check(int x) {
    int cur = 0, mn = 0, mx = 0;
    for (auto &p : v) {
        if (p.first > mx) {
            if (mx + x < p.first) return false;
            mn = p.first;
            mx = min(p.second, mx + x);
        }
        else if (p.second < mn) {
            if (mn - x > p.second) return false;
            mn = max(mn - x, p.first);
            mx = p.second;
        }
        else {
            mn = max(p.first, mn - x);
            mx = min(p.second, mx + x);
        }
    }
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back({a, b});
        }
        int l = 0, r = 1e9, ans = 0x3f3f3f3f;
        while (l <= r) {
            int m = (l + r)/2;
            if (check(m)) {
                ans = min(ans, m);
                r = m - 1;
            }
            else l = m + 1;
        }
        cout << ans << "\n";
        v.clear();
    }
    return 0;
}
