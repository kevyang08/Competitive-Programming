#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, x, y, st[2][400005], rx, ry, mx, cnt = 0;
map<int, int> mp, inv;
void update(int l, int r, int i, int k, int v, int idx) {
    if (l == r) {
        st[k][idx] += v;
        return;
    }
    int m = (l + r)/2;
    if (i > m) update(m + 1, r, i, k, v, 2 * idx + 1);
    else update(l, m, i, k, v, 2 * idx);
    st[k][idx] = st[k][2 * idx] + st[k][2 * idx + 1];
}
void check1(int l, int r, int lc1, int rc1, int lc2, int rc2, int cx, int idx) {

    // cout << "Check1: " << l << " " << r << " " << lc1 << " " << lc2 << " " << rc1 << " " << rc2 << " " << cx << " debug\n";

    if (l == r) {
        if (min(lc1 + st[0][idx], lc2 + st[1][idx]) <= min(rc1, rc2) && min(lc1 + st[0][idx], lc2 + st[1][idx]) >= mx) {
            mx = min(lc1 + st[0][idx], lc2 + st[1][idx]);
            rx = cx;
            ry = inv[l + 1];
        }
        return;
    }
    int m = (l + r)/2;
    if (min(lc1 + st[0][2 * idx], lc2 + st[1][2 * idx]) <= min(rc1 + st[0][2 * idx + 1], rc2 + st[1][2 * idx + 1])) {
        if (min(lc1 + st[0][2 * idx], lc2 + st[1][2 * idx]) >= mx) {
            mx = min(lc1 + st[0][2 * idx], lc2 + st[1][2 * idx]);
            rx = cx;
            ry = inv[m + 1];
        }
        check1(m + 1, r, lc1 + st[0][2 * idx], rc1, lc2 + st[1][2 * idx], rc2, cx, 2 * idx + 1);
    }
    else check1(l, m, lc1, rc1 + st[0][2 * idx + 1], lc2, rc2 + st[1][2 * idx + 1], cx, 2 * idx);
}
void check2(int l, int r, int lc1, int rc1, int lc2, int rc2, int cx, int idx) {

    // cout << "Check2: " << l << " " << r << " " << lc1 << " " << lc2 << " " << rc1 << " " << rc2 << " " << cx << " debug\n";

    if (l == r) {
        if (min(rc1 + st[0][idx], rc2 + st[1][idx]) <= min(lc1, lc2) && min(rc1 + st[0][idx], rc2 + st[1][idx]) >= mx) {
            mx = min(rc1 + st[0][idx], rc2 + st[1][idx]);
            rx = cx;
            ry = inv[l];
        }
        return;
    }
    int m = (l + r)/2;
    if (min(rc1 + st[0][2 * idx + 1], rc2 + st[1][2 * idx + 1]) <= min(lc1 + st[0][2 * idx], lc2 + st[1][2 * idx])) {
        if (min(rc1 + st[0][2 * idx + 1], rc2 + st[1][2 * idx + 1]) >= mx) {
            mx = min(rc1 + st[0][2 * idx + 1], rc2 + st[1][2 * idx + 1]);
            rx = cx;
            ry = inv[m + 1];
        }
        check2(l, m, lc1, rc1 + st[0][2 * idx + 1], lc2, rc2 + st[1][2 * idx + 1], cx, 2 * idx);
    }
    else check2(m + 1, r, lc1 + st[0][2 * idx], rc1, lc2 + st[1][2 * idx], rc2, cx, 2 * idx + 1);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cnt = rx = ry = mx = 0;
        cin >> n;
        fill(st[0], st[0] + 4 * n + 1, 0);
        fill(st[1], st[1] + 4 * n + 1, 0);
        mp.clear();
        inv.clear();
        map<int, int> coords;
        map<int, vector<int>, greater<int>> sweep;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            ++coords[y];
            sweep[x].push_back(y);
        }
        for (auto &[c, v] : coords) mp[c] = ++cnt, inv[cnt] = c;
        for (auto &[c, v] : coords) update(1, n, mp[c], 0, v, 1);
        for (auto &[k, v] : sweep) {
            for (int j : v) update(1, n, mp[j], 0, -1, 1), update(1, n, mp[j], 1, 1, 1);
            check1(1, n, 0, 0, 0, 0, k, 1);
            check2(1, n, 0, 0, 0, 0, k, 1);
        }
        cout << mx << "\n";
        cout << rx << " " << ry << "\n";
    }
    return 0;
}