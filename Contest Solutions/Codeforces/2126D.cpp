#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, l, r, e;
void solve() {
    cin >> n >> k;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> e;
        v.push_back({e, l, r});
    }
    sort(v.begin(), v.end());
    for (auto &[a, b, c] : v) {
        if (k >= a) continue;
        if (b <= k && k <= c) k = a;
    }
    cout << k << "\n";
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