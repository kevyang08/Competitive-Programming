#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, t, x_1, y_1, x_2, y_2, ti, px = 0, py = 0, ct = 0;
vector<pair<pair<pair<int, int>, int>, int>> v;
vector<int> x;
long long cc = 0, ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> x_1 >> y_1 >> x_2 >> y_2 >> ti;
        v.push_back({{{y_1, x_1}, x_2}, ti});
        v.push_back({{{y_2, x_1}, x_2}, -ti});
        x.push_back(x_1);
        x.push_back(x_2);
    }
    sort(v.begin(), v.end());
    sort(x.begin(), x.end());
    for (int i : x) {
        ans += cc * (i - px);
        cc = ct = py = 0;
        for (pair p : v) {
            if (p.fi.fi.se > i || p.fi.se <= i) continue;
            if (ct >= t) cc += p.fi.fi.fi - py;
            ct += p.se;
            py = p.fi.fi.fi; // bruh wtf
        }
        px = i;
    }
    cout << ans << "\n";
}
