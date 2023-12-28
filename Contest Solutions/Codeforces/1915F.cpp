#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, bit[400001];
void update(int i, int v) {
    for (; i <= 2 * n; i += (i & -i)) bit[i] += v;
}
int query(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n;
        vector<pair<int, int>> v;
        vector<int> c;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back({a, b});
            c.push_back(a);
            c.push_back(b);
        }
        sort(v.begin(), v.end());
        sort(c.begin(), c.end());
        for (int i = 1; i <= 2 * n; i++) mp[c[i - 1]] = i;
        for (int i = 0; i < n; i++) update(mp[v[i].second], 1);
        for (int i = 0; i < n; i++) {
            update(mp[v[i].second], -1);
            ans += query(mp[v[i].second]);
        }
        cout << ans << "\n";
    }
    return 0;
}
