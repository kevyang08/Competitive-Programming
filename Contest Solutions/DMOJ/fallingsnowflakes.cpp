#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, q, a, b, c, d, t, bit[5001][5001], ans[100001], ids = 0, idq = 0;
char op;
vector<pair<pair<int, int>, pair<int, int>>> v;
vector<pair<pair<int, int>, pair<char, pair<pair<int, int>, pair<int, int>>>>> vq;
vector<int> vt;
void update(int r, int c, int v) {
    for (; r <= n; r += (r & -r)) for (int j = c; j <= n; j += (j & -j)) bit[r][j] += v;
}
int query(int r, int c) {
    int res = 0;
    for (; r > 0; r -= (r & -r)) for (int j = c; j > 0; j -= (j & -j)) res += bit[r][j];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c >> d;
        a++; b++;
        v.push_back({{c, 1}, {a, b}});
        v.push_back({{d, -1}, {a, b}});
        vt.push_back(c);
        vt.push_back(d);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= q; i++) {
        cin >> op >> a >> b;
        if (op == 'V') cin >> c >> d;
        cin >> t;
        b++; d++;
        vq.push_back({{t, i}, {op, {{a, b}, {c, d}}}});
        vt.push_back(t);
    }
    sort(vq.begin(), vq.end());
    sort(vt.begin(), vt.end());
    for (int i : vt) {
        while (ids < 2 * m && v[ids].fi.fi == i) {
            update(v[ids].se.fi, v[ids].se.se, v[ids].fi.se);
            ids++;
        }
        while (idq < q && vq[idq].fi.fi == i) {
            if (vq[idq].se.fi == 'R') ans[vq[idq].fi.se] = query(vq[idq].se.se.fi.se, n) - query(vq[idq].se.se.fi.fi, n);
            else if (vq[idq].se.fi == 'C') ans[vq[idq].fi.se] = query(n, vq[idq].se.se.fi.se) - query(n, vq[idq].se.se.fi.fi);
            else ans[vq[idq].fi.se] = query(vq[idq].se.se.fi.se, n) - query(vq[idq].se.se.fi.fi, n) + query(n, vq[idq].se.se.se.se) - query(n, vq[idq].se.se.se.fi) - (query(vq[idq].se.se.fi.se, vq[idq].se.se.se.se) - query(vq[idq].se.se.fi.fi, vq[idq].se.se.se.se) - query(vq[idq].se.se.fi.se, vq[idq].se.se.se.fi) + query(vq[idq].se.se.fi.fi, vq[idq].se.se.se.fi));
            idq++;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
