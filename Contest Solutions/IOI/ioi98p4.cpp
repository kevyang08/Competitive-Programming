#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, a, b, c, d, px = 0, py = 0, cc = 0, ca = 0;
long long ans = 0;
vector<pair<pair<int, pair<int, int>>, int>> vx, vy;
vector<int> x, y;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        vy.push_back({{b, {a, c}}, 1});
        vy.push_back({{d, {a, c}}, -1});
        vx.push_back({{a, {b, d}}, 1});
        vx.push_back({{c, {b, d}}, -1});
        x.push_back(a);
        x.push_back(c);
        y.push_back(b);
        y.push_back(d);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < 2 * n; i++) {
        if (i < 2 * n - 1 && x[i] == x[i + 1]) continue;
        ans += cc * (x[i] - px);
        cc = ca = 0;
        for (int j = 0; j < 2 * n; j++) {
            if (vy[j].fi.se.fi > x[i] || vy[j].fi.se.se <= x[i]) continue;
            ca += vy[j].se;
            if (j < 2 * n - 1 && vy[j].fi.fi == vy[j + 1].fi.fi && vy[j + 1].fi.se.fi <= x[i] && vy[j + 1].fi.se.se > x[i]) continue;
            if (ca == 0) cc++;
        }
        for (int j = 2 * n - 1; j >= 0; j--) {
            if (vy[j].fi.se.fi > x[i] || vy[j].fi.se.se <= x[i]) continue;
            ca += vy[j].se;
            if (j > 0 && vy[j].fi.fi == vy[j - 1].fi.fi && vy[j - 1].fi.se.fi <= x[i] && vy[j - 1].fi.se.se > x[i]) continue;
            if (ca == 0) cc++;
        }
        px = x[i];
    }
    cc = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i < 2 * n - 1 && y[i] == y[i + 1]) continue;
        ans += cc * (y[i] - py);
        cc = ca = 0;
        for (int j = 0; j < 2 * n; j++) {
            if (vx[j].fi.se.fi > y[i] || vx[j].fi.se.se <= y[i]) continue;
            ca += vx[j].se;
            if (j < 2 * n - 1 && vx[j].fi.fi == vx[j + 1].fi.fi && vx[j + 1].fi.se.fi <= y[i] && vx[j + 1].fi.se.se > y[i]) continue;
            if (ca == 0) cc++;
        }
        for (int j = 2 * n - 1; j >= 0; j--) {
            if (vx[j].fi.se.fi > y[i] || vx[j].fi.se.se <= y[i]) continue;
            ca += vx[j].se;
            if (j > 0 && vx[j].fi.fi == vx[j - 1].fi.fi && vx[j - 1].fi.se.fi <= y[i] && vx[j - 1].fi.se.se > y[i]) continue;
            if (ca == 0) cc++;
        }
        py = y[i];
    }
    cout << ans << "\n";
    return 0;
}
