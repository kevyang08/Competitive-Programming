#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
considering each index i as a range [l[i] = min(a[i], b[i]), r[i] = max(a[i], b[i])], if any overlap, ans remains same
if no overlap, find pair i, j with minimum l[j] - r[i];

*/

int t, n, k, a[200001], b[200001];
void solve() {
    cin >> n >> k;
    ll ans = 0;
    vector<pair<int, int>> v;
    set<int> st;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
        ans += b[i] - a[i];
        v.push_back({b[i], -a[i]});
    }
    sort(v.begin(), v.end());
    for (auto &[r, l] : v) {
        l = -l;
        if (st.lower_bound(l) != st.end() && *st.lower_bound(l) <= r) {
            cout << ans << "\n";
            return;
        }
        st.insert(r);
    }
    int mn = INF;
    for (int i = 1; i < n; i++) mn = min(mn, v[i].se - v[i - 1].fi);
    // cout << mn << " what\n";
    cout << ans + mn * 2 << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}