#include <bits/stdc++.h>
using namespace std;

int n, q, l, r;
long long v, st[800005];
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
long long query(int l, int r, int ql, int qr, int idx, long long v) {
    if (r < ql || l > qr || st[idx] > v) return -1;
    if (l == r) return v%st[idx];
    int m = (l + r) >> 1;
    long long res = -1;
    if (m >= ql) res = query(l, m, ql, qr, idx << 1, v);
    return (res != -1 ? res : query(m + 1, r, ql, qr, idx << 1 | 1, v));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    build(1, n, 1);
    while (q--) {
        cin >> v >> l >> r;
        while (true) {
            long long res = query(1, n, l, r, 1, v);
            if (res != -1) v = res;
            else break;
        }
        cout << v << "\n";
    }
    return 0;
}
