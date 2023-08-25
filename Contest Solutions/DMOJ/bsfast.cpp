#include <bits/stdc++.h>
using namespace std;

int n, q, op, p, x, l, r, k, ans = 0, st[4000005];
void build(int l, int r, int idx) {
    if (l == r) {
        cin >> st[idx];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, idx << 1);
    build(m + 1, r, idx << 1 | 1);
    st[idx] = min(st[idx << 1], st[idx << 1 | 1]);
}
void update(int l, int r, int qi, int idx, int v) {
    if (l == r) {
        st[idx] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (qi <= m) update(l, m, qi, idx << 1, v);
    else update(m + 1, r, qi, idx << 1 | 1, v);
    st[idx] = min(st[idx << 1], st[idx << 1 | 1]);
}
int query(int l, int r, int ql, int qr, int idx, int k) {
    if (r < ql || st[idx] >= k) return 0x3f3f3f3f;
    if (l == r) return l;
    int m = (l + r) >> 1, res = 0x3f3f3f3f;
    if (m >= ql) res = query(l, m, ql, qr, idx << 1, k);
    return (res != 0x3f3f3f3f ? res : query(m + 1, r, ql, qr, idx << 1 | 1, k));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    build(1, n, 1);
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> p >> x;
            p ^= ans; x ^= ans;
            update(1, n, p, 1, x);
        }
        else {
            cin >> l >> r >> k;
            l ^= ans; r ^= ans; k ^= ans;
            ans = query(1, n, l, r, 1, k);
            cout << ans << "\n";
        }
    }
    return 0;
}
