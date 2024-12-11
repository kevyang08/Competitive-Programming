#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// watch out for duplicates

int t, n, l[200000], r[200000];
set<int> stl;
set<int, greater<int>> str;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<pair<int, int>, int>> vl, vr;
        vector<int> ans(n);
        vector<int> coords;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            coords.push_back(l[i]), coords.push_back(r[i]);
            ++mp[{l[i], r[i]}];
            vl.push_back({{l[i], r[i]}, i});
            vr.push_back({{r[i], l[i]}, i});
        }
        sort(coords.begin(), coords.end());
        sort(vl.begin(), vl.end(), [&](auto a, auto b) {
            return a.fi.fi != b.fi.fi ? a.fi.fi < b.fi.fi : a.fi.se > b.fi.se;    
        });
        for (int i = 0, j = 0; i < 2 * n; i++) {
            while (j < n && vl[j].fi.fi == coords[i]) {
                if (!stl.empty() && stl.lower_bound(vl[j].fi.se) != stl.end()) ans[vl[j].se] += *stl.lower_bound(vl[j].fi.se) - vl[j].fi.se;
                stl.insert(vl[j].fi.se);
                ++j;
            }
            while (!stl.empty() && *stl.begin() <= coords[i]) stl.erase(*stl.begin());
        }
        reverse(coords.begin(), coords.end());
        sort(vr.begin(), vr.end(), [&](auto a, auto b) {
            return a.fi.fi != b.fi.fi ? a.fi.fi > b.fi.fi : a.fi.se < b.fi.se;    
        });
        for (int i = 0, j = 0; i < 2 * n; i++) {
            while (j < n && vr[j].fi.fi == coords[i]) {
                if (!str.empty() && str.lower_bound(vr[j].fi.se) != str.end()) ans[vr[j].se] += vr[j].fi.se - *str.lower_bound(vr[j].fi.se);
                str.insert(vr[j].fi.se);
                ++j;
            }
            while (!str.empty() && *str.begin() >= coords[i]) str.erase(*str.begin());
        }
        for (int i = 0; i < n; i++) if (mp[{l[i], r[i]}] > 1) ans[i] = 0;
        for (int i : ans) cout << i << "\n";
    }
    return 0;
}