#include <bits/stdc++.h>
using namespace std;

int t, n, q, ql, qr, a[1000050], lazy[4000050], mndx[4000050], mxdx[4000050];
long long mn[4000050], mx[4000050];
void build(int l, int r, int idx) {
    lazy[idx] = 0;
    if (l == r) {
        mn[idx] = mx[idx] = a[l];
        mndx[idx] = mxdx[idx] = l;
        return;
    }
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    if (mn[2 * idx] <= mn[2 * idx + 1]) mndx[idx] = mndx[2 * idx];
    else mndx[idx] = mndx[2 * idx + 1];
    mn[idx] = min(mn[2 * idx], mn[2 * idx + 1]);
    if (mx[2 * idx] >= mx[2 * idx + 1]) mxdx[idx] = mxdx[2 * idx];
    else mxdx[idx] = mxdx[2 * idx + 1];
    mx[idx] = max(mx[2 * idx], mx[2 * idx + 1]);
}
void pushDown(int l, int r, int idx) {
    if (lazy[idx]%2) {
        mn[idx] = (mn[idx] * 1000000006)%1000000007;
        mx[idx] = (mx[idx] * 1000000006)%1000000007;
        if (mn[idx] > mx[idx]) {
            long long temp = mn[idx];
            mn[idx] = mx[idx];
            mx[idx] = temp;
            int tidx = mndx[idx];
            mndx[idx] = mxdx[idx];
            mxdx[idx] = tidx;
        }
        if (l != r) {
            lazy[2 * idx]++;
            lazy[2 * idx + 1]++;
        }
        lazy[idx] = 0;
    }
}
void update(int l, int r, int ql, int qr, int idx) {
    pushDown(l, r, idx);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        long long temp = mn[idx];
        mn[idx] = (mx[idx] * 1000000006)%1000000007;
        mx[idx] = (temp * 1000000006)%1000000007;
        if (mn[idx] != mx[idx]) {
            int tidx = mndx[idx];
            mndx[idx] = mxdx[idx];
            mxdx[idx] = tidx;
        }
        if (l != r) {
            lazy[2 * idx]++;
            lazy[2 * idx + 1]++;
        }
        return;
    }
    int m = (l + r)/2;
    update(l, m, ql, qr, 2 * idx);
    update(m + 1, r, ql, qr, 2 * idx + 1);
    if (mn[2 * idx] <= mn[2 * idx + 1]) mndx[idx] = mndx[2 * idx];
    else mndx[idx] = mndx[2 * idx + 1];
    mn[idx] = min(mn[2 * idx], mn[2 * idx + 1]);
    if (mx[2 * idx] >= mx[2 * idx + 1]) mxdx[idx] = mxdx[2 * idx];
    else mxdx[idx] = mxdx[2 * idx + 1];
    mx[idx] = max(mx[2 * idx], mx[2 * idx + 1]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("today_is_gonna_be_a_great_day_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        long long ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1, n, 1);
        cin >> q;
        while (q--) {
            cin >> ql >> qr;
            update(1, n, ql, qr, 1);
            ans += mxdx[1];
        }
        cout << "Case #" << bruh << ": " << ans << "\n";
    }
    return 0;
}
