#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0x3f3f3f3f;
        set<int> st;
        set<int, greater<int>> sr;
        cin >> n;
        vector<pair<int, int>> v(n);
        vector<int> mx(n);
        for (auto &[i, j] : v) cin >> i >> j;
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b) -> bool {
            return a.first != b.first ? a.first < b.first : a.second > b.second;
        });
        mx[n - 1] = -ans;
        for (int i = n - 2; i >= 0; i--) mx[i] = max(mx[i + 1], v[i + 1].second);
        for (int i = 0; i < n; i++) {
            ans = min(ans, abs(v[i].first - mx[i]));
            if (st.lower_bound(v[i].first) != st.end()) ans = min(ans, abs(v[i].first - max(mx[i], *st.lower_bound(v[i].first))));
            if (sr.lower_bound(v[i].first) != sr.end()) ans = min(ans, abs(v[i].first - max(mx[i], *sr.lower_bound(v[i].first))));
            st.insert(v[i].second);
            sr.insert(v[i].second);
        }
        cout << ans << "\n";
    }
    return 0;
}