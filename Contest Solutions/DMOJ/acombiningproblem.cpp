#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mn, mx, lz = 0, rs = 0x3f3f3f3f;
};
Node st[400005];
int n, q, op, a, b, psa[100005];
void build(int l, int r, int idx) {
    if (l == r) {
        st[idx].mn = st[idx].mx = l;
        return;
    }
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    st[idx].mn = st[2 * idx].mn;
    st[idx].mx = st[2 * idx + 1].mx;
}
void lazy(int l, int r, int idx) {
    if (st[idx].rs != 0x3f3f3f3f) {
        if (l != r) {
            st[2 * idx].lz = st[2 * idx + 1].lz = 0;
            int m = (l + r)/2;
            if (st[idx].rs > 0) st[2 * idx].mn = st[2 * idx].mx = st[2 * idx + 1].mn = st[2 * idx + 1].mx = st[idx].rs;
            else {
                st[2 * idx].mn = l + st[idx].rs;
                st[2 * idx].mx = m + st[idx].rs;
                st[2 * idx + 1].mn = m + 1 + st[idx].rs;
                st[2 * idx + 1].mx = r + st[idx].rs;
            }
            st[2 * idx].rs = st[2 * idx + 1].rs = st[idx].rs;
        }
        st[idx].rs = 0x3f3f3f3f;
    }
    if (st[idx].lz) {
        if (l != r) {
            st[2 * idx].lz += st[idx].lz;
            st[2 * idx + 1].lz += st[idx].lz;
            st[2 * idx].mn += st[idx].lz;
            st[2 * idx].mx += st[idx].lz;
            st[2 * idx + 1].mn += st[idx].lz;
            st[2 * idx + 1].mx += st[idx].lz;
        }
        st[idx].lz = 0;
    }
}
void reset(int l, int r, int ql, int qr, int v, int idx) {
    lazy(l, r, idx);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        st[idx].lz = 0;
        if (v > 0) st[idx].mn = st[idx].mx = v;
        else {
            st[idx].mn = l + v;
            st[idx].mx = r + v;
        }
        if (l != r) st[idx].rs = v;
        return;
    }
    int m = (l + r)/2;
    reset(l, m, ql, qr, v, 2 * idx);
    reset(m + 1, r, ql, qr, v, 2 * idx + 1);
    st[idx].mn = st[2 * idx].mn;
    st[idx].mx = st[2 * idx + 1].mx;
}
void update(int l, int r, int ql, int qr, int v, int idx) {
    lazy(l, r, idx);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        st[idx].mn += v;
        st[idx].mx += v;
        if (l != r) st[idx].lz += v;
        return;
    }
    int m = (l + r)/2;
    update(l, m, ql, qr, v, 2 * idx);
    update(m + 1, r, ql, qr, v, 2 * idx + 1);
    st[idx].mn = st[2 * idx].mn;
    st[idx].mx = st[2 * idx + 1].mx;
}
int bs(int l, int r, int v, int idx) {
    lazy(l, r, idx);
    if (l == r) return v > st[idx].mx ? l + 1 : l;
    int m = (l + r)/2;
    if (v <= st[2 * idx].mx) return bs(l, m, v, 2 * idx);
    else return bs(m + 1, r, v, 2 * idx + 1);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    while (q--) {
        cin >> op >> a;
        int m = st[1].mx;
        if (a > m) a -= (int)ceil((double)(a - m)/m) * m;
        if (op == 1) {
            cin >> b;
            int bruh = m + 1 - a;
            if (b > bruh) b -= (int)ceil((double)(b - bruh)/bruh) * bruh;
            int l = bs(1, n, a, 1), r = bs(1, n, a + b, 1) - 1;
            reset(1, n, l, r, a, 1);
            if (r < n) update(1, n, r + 1, n, 1 - b, 1);
        }
        else if (op == 2) {
            int l = bs(1, n, a, 1), r = bs(1, n, a + 1, 1) - 1;
            reset(1, n, l, r, a - l, 1);
            if (r < n) update(1, n, r + 1, n, r - l, 1);
        }
        else {
            cin >> b;
            int bruh = m + 1 - a;
            if (b > bruh) b -= (int)ceil((double)(b - bruh)/bruh) * bruh;
            int l = bs(1, n, a, 1), r = bs(1, n, a + b, 1) - 1;
            cout << psa[r] - psa[l - 1] << "\n";
        }
    }
    return 0;
}
