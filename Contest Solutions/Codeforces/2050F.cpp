#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, q, l, r, a[200005], st[800005];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = 0;
        return;
    }
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    st[idx] = gcd(gcd(st[2 * idx], st[2 * idx + 1]), abs(a[m] - a[m + 1]));
}
int query(int l, int r, int ql, int qr, int idx) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return st[idx];
    int m = (l + r)/2, rl = query(l, m, ql, qr, 2 * idx), rr = query(m + 1, r, ql, qr, 2 * idx + 1);
    if (m < ql) return rr;
    if (m >= qr) return rl;
    return gcd(gcd(rl, rr), abs(a[m] - a[m + 1]));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1, n, 1);
        while (q--) {
            cin >> l >> r;
            cout << query(1, n, l, r, 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}