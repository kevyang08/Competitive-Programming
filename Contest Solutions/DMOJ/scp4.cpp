#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
post-submission notes:
- block size 45 is the fastest for some reason
- apparently the intended solution is nmlognlogm, not nmsqrtnlogm
    - probably figure out how to do that sometime
*/

const int sz = 45;

int n, m, q, g[2001][2001], op, r, c, v;
ll bit[2001][2001], sbit[sz][2101], rbit[2001][2001];
void update(int r, int c, int v) {
    // cout << r << " " << c << " bruh\n";
    for (int i = r; i <= n; i += (i & -i)) for (int j = c; j <= m; j += (j & -j)) bit[i][j] += v;
    for (int j = c; j <= m; j += (j & -j)) rbit[r][j] += v;
    int idx = r/sz;
    for (int j = c + sz - r + idx * sz + 1; j <= m + sz; j += (j & -j)) sbit[idx][j] += v;
}
ll query(int i, int c) {
    ll res = 0;
    for (; i > 0; i -= (i & -i)) for (int j = c; j > 0; j -= (j & -j)) res += bit[i][j];
    return res;
}
ll queryR(int i, int j) {
    ll res = 0;
    for (; j > 0; j -= (j & -j)) res += rbit[i][j];
    return res;
}
ll queryS(int i, int c) {
    ll res = 0;
    for (int j = c + sz + 1; j > 0; j -= (j & -j)) res += sbit[i][j];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            update(i, j, g[i][j]);
        }
    }
    while (q--) {
        cin >> op >> r >> c >> v;
        if (op == 1) {
            update(r, c, v - g[r][c]);
            g[r][c] = v;
        }
        else {
            int lo = (r - v + 1)/sz, hi = r/sz, rl = r - v + 1;
            ll ans = 0;
            for (int i = rl; i < min((lo + 1) * sz, r + 1); i++) ans += queryR(i, c + i - rl) - queryR(i, c - 1);
            if (lo != hi) for (int i = hi * sz; i <= r; i++) ans += queryR(i, c + i - rl) - queryR(i, c - 1);
            for (int i = lo + 1; i < hi; i++) ans += queryS(i, c + i * sz - rl);
            if (lo + 1 < hi) ans -= query(hi * sz - 1, c - 1) - query((lo + 1) * sz - 1, c - 1);
            cout << ans << "\n";
        }
    }
    // cout << queryS(0, 3, 4) << " bruh\n";
    return 0;
}