#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int sz = 801;

int n, q, a[500001], l, r, k, ans[500001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    vector<vector<pair<pair<int, int>, pair<int, int>>>> vq(sz);
    vector<int> cnt(n + 1);
    vector<vector<int>> v(n + 1);
    vector<int> id(n + 1);
    vector<int> mn(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = v[a[i]].size();
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> l >> r >> k;
        vq[l/sz].push_back({{l, r}, {k, i}});
    }
    a[0] = -1;
    for (int k = 0; k < sz; k++) {
        if (vq[k].empty()) continue;
        int hi = min(k * sz + sz - 1, n), j = hi, m = 0;
        sort(vq[k].begin(), vq[k].end(), [&](const auto &a, const auto &b) -> bool {
            return a.fi.se < b.fi.se;
        });
        for (auto [lr, b] : vq[k]) {
            auto [l, r] = lr;
            auto [k, idx] = b;
            while (j < r) {
                ++cnt[a[++j]];
                if (cnt[a[j]] > m) mn[++m] = j;
            }
            int res = mn[k];
            for (int i = l; i <= min(hi, r); i++) {
                int tmp = id[i] + k - 1;
                if (tmp < v[a[i]].size() && (!res || v[a[i]][tmp] <= res) && v[a[i]][tmp] <= r) res = v[a[i]][tmp];
            }
            ans[idx] = a[res];
        }
        for (int i = max(k * sz, 1); i <= j; i++) cnt[a[i]] = 0;
        for (int i = 1; i <= m; i++) mn[i] = 0;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}