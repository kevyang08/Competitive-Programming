#include <bits/stdc++.h>
using namespace std;

int n, q, lm, a, b, tree[4000001], lazy[4000001];
void build(int l, int r, int idx) {
    if (l == r) {
        tree[idx] = 1; 
        return;
    }
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}
void update(int l, int r, int ql, int qr, int idx) {
    if (lazy[idx]) {
        tree[idx] = r - l + 1 - tree[idx];
        if (l != r) {
            lazy[2 * idx] ^= 1;
            lazy[2 * idx + 1] ^= 1;
        }
        lazy[idx] = 0;
    }
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        tree[idx] = r - l + 1 - tree[idx];
        if (l != r) {
            lazy[2 * idx] ^= 1;
            lazy[2 * idx + 1] ^= 1;
        }
        return;
    }
    int m = (l + r)/2;
    update(l, m, ql, qr, 2 * idx);
    update(m + 1, r, ql, qr, 2 * idx + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}
int query(int l, int r, int ql, int qr, int idx) {
    if (lazy[idx]) {
        tree[idx] = r - l + 1 - tree[idx];
        if (l != r) {
            lazy[2 * idx] ^= 1;
            lazy[2 * idx + 1] ^= 1;
        }
        lazy[idx] = 0;
    }
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return tree[idx];
    int m = (l + r)/2;
    return query(l, m, ql, qr, 2 * idx) + query(m + 1, r, ql, qr, 2 * idx + 1);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q >> lm;
    build(1, n, 1);
    while (q--) {
        cin >> a >> b;
        update(1, n, a, b, 1);
        int l = 1, r = n, res = -1;
        while (l <= r) {
            int m = (l + r)/2, bruh = query(1, n, 1, m, 1);
            if (bruh == lm) res = m;
            if (bruh < lm) l = m + 1;
            else r = m - 1;
        }
        if (res == -1) cout << "AC?\n";
        else cout << res << "\n";
    }
}
