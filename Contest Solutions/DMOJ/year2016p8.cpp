#include <bits/stdc++.h>
using namespace std;

int n, q, op, l, r;
struct Node {
    int v = 0, pr = 0, su = 0, l = 0, r = 0, lz = 0;
} st[400005];
void pushDown(int idx, int l, int r) {
    if (st[idx].lz) {
        if (l != r) st[idx << 1].lz = st[idx << 1 | 1].lz = st[idx].lz;
        if (st[idx].lz == 1) st[idx] = {r - l + 1, r - l + 1, r - l + 1, l, r, 0};
        else st[idx] = {0, 0, 0, 0, 0, 0};
    }
}
void update(int l, int r, int ql, int qr, int idx, int op) {
    pushDown(idx, l, r);
    if (ql <= l && r <= qr) {
        if (op) {
            st[idx] = {r - l + 1, r - l + 1, r - l + 1, l, r, 0};
            if (l != r) st[idx << 1].lz = st[idx << 1 | 1].lz = 1;
        }
        else {
            st[idx] = {0, 0, 0, 0, 0, 0};
            if (l != r) st[idx << 1].lz = st[idx << 1 | 1].lz = -1;
        }
        return;
    }
    if (l > qr || r < ql) return;
    int m = (l + r) >> 1;
    update(l, m, ql, qr, idx << 1, op);
    update(m + 1, r, ql, qr, idx << 1 | 1, op);
    if (st[idx << 1].pr == m - l + 1) st[idx].pr = m - l + 1 + st[idx << 1 | 1].pr;
    else st[idx].pr = st[idx << 1].pr;
    if (st[idx << 1 | 1].su == r - m) st[idx].su = r - m + st[idx << 1].su;
    else st[idx].su = st[idx << 1 | 1].su;
    if (st[idx << 1].v >= st[idx << 1 | 1].v) {
        st[idx].v = st[idx << 1].v;
        st[idx].l = st[idx << 1].l;
        st[idx].r = st[idx << 1].r;
    }
    else {
        st[idx].v = st[idx << 1 | 1].v;
        st[idx].l = st[idx << 1 | 1].l;
        st[idx].r = st[idx << 1 | 1].r;
    }
    if (st[idx << 1].su + st[idx << 1 | 1].pr > st[idx].v || st[idx << 1].su + st[idx << 1 | 1].pr == st[idx].v && m + st[idx << 1 | 1].pr <= st[idx].l) {
        st[idx].v = st[idx << 1].su + st[idx << 1 | 1].pr;
        st[idx].l = m - st[idx << 1].su + 1;
        st[idx].r = m + st[idx << 1 | 1].pr;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        cin >> op;
        if (op == 2) update(1, n, st[1].l, st[1].r, 1, 0);
        else {
            cin >> l >> r;
            update(1, n, l, r, 1, op);
            cout << st[1].v << "\n";
        }
    }
    return 0;
}
