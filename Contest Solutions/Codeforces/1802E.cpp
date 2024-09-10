#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, k, a, bit[200001], bruh;
void update(int i, int v) {
    for (; i <= bruh; i += (i & -i)) bit[i] = max(bit[i], v);
}
int query(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res = max(res, bit[i]);
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        vector<vector<int>> v(n);
        vector<int> c;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> k;
            int mx = 0;
            for (int j = 0; j < k; j++) {
                cin >> a;
                if (a > mx) {
                    v[i].push_back(a);
                    mx = a;
                }
                c.push_back(a);
            }
        }
        sort(c.begin(), c.end());
        bruh = c.size();
        for (int i = 1; i <= bruh; i++) mp[c[i - 1]] = i;
        fill(bit, bit + bruh + 1, 0);
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b) -> bool {
            return a.back() < b.back();
        });
        for (const auto &l : v) {
            int m = l.size(), mx = m;
            for (int i = 1; i <= m; i++) mx = max(mx, i + query(mp[l[m - i]] - 1));
            update(mp[l.back()], mx);
            ans = max(ans, mx);
        }
        cout << ans << "\n";
    }
    return 0;
}