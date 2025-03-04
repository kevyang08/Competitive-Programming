#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, xr, x, y, vi, bit[10005];
ll ans[200005], res = 0;
vector<pair<pair<int, int>, int>> v;
void update(int i) {
    for (; i > 0; i -= (i & -i)) ++bit[i];
}
int query(int i) {
    int res = 0;
    for (; i <= 10000; i += (i & -i)) res += bit[i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> xr;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        v.push_back({{x, y}, i});
    }
    sort(v.begin(), v.end(), [&](auto a, auto b) { // sort relative to (0, 0)
        return a.fi.fi * b.fi.se != b.fi.fi * a.fi.se ? a.fi.fi * b.fi.se < b.fi.fi * a.fi.se : a.fi.se > b.fi.se;
    });
    for (auto &[a, b] : v) {
        ans[b] += query(a.se);
        update(a.se);
    }
    fill(bit, bit + 10001, 0);
    sort(v.begin(), v.end(), [&](auto a, auto b) { // sort relative to (xr, 0)
        return (a.fi.fi - xr) * b.fi.se != (b.fi.fi - xr) * a.fi.se ? (a.fi.fi - xr) * b.fi.se < (b.fi.fi - xr) * a.fi.se : a.fi.se < b.fi.se;
    });
    for (auto &[a, b] : v) {
        ans[b] -= query(a.se);
        update(a.se);
    }
    for (int i = 1; i <= n; i++) res += ans[i] * ans[i];
    cout << res << "\n";
    return 0;
}