#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, a, b, c, d, ans = 0, px = 0, aa = 0, cc, py;
vector<pair<pair<int, pair<int, int>>, int>> v;
vector<int> x;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        v.push_back({{b, {a, c}}, 1});
        v.push_back({{d, {a, c}}, -1});
        x.push_back(a);
        x.push_back(c);
    }
    sort(v.begin(), v.end());
    sort(x.begin(), x.end());
    for (int i : x) {
        ans += aa * (i - px);
        aa = cc = py = 0;
        for (pair p : v) {
            if (p.fi.se.fi > i || p.fi.se.se <= i) continue;
            if (cc) aa += p.fi.fi - py;
            cc += p.se;
            py = p.fi.fi;
        }
        px = i;
    }
    cout << ans << "\n";
    return 0;
}
