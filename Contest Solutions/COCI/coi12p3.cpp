#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, op, x, y, a[200005], mn[800005], mx[800005];
void update(int l, int r, int i, int v, int idx) {
    if (l == r) {
        mn[idx] = mx[idx] = v;
        return;
    }
    int m = (l + r)/2;
    if (i > m) update(m + 1, r, i, v, 2 * idx + 1);
    else update(l, m, i, v, 2 * idx);
    mn[idx] = min(mn[2 * idx], mn[2 * idx + 1]);
    mx[idx] = max(mx[2 * idx], mx[2 * idx + 1]);
}
pair<int, int> query(int l, int r, int ql, int qr, int idx) {
    if (l > qr || r < ql) return {-1, -1};
    if (ql <= l && r <= qr) return {mn[idx], mx[idx]};
    int m = (l + r)/2;
    auto rl = query(l, m, ql, qr, 2 * idx), rr = query(m + 1, r, ql, qr, 2 * idx + 1);
    if (rl.fi == -1) return rr;
    else if (rr.fi == -1) return rl;
    return {min(rl.fi, rr.fi), max(rl.se, rr.se)};
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, n, a[i], i, 1);
    }
    while (m--) {
        cin >> op >> x >> y;
        if (op == 1) {
            update(1, n, a[x], y, 1);
            update(1, n, a[y], x, 1);
            swap(a[x], a[y]);
        }
        else {
            auto [l, r] = query(1, n, x, y, 1);
            cout << (r - l + 1 == y - x + 1 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}