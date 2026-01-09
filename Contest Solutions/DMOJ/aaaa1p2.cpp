#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, m, l, f;
ll pref[400005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<pair<ll, int>> v;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> l;
        v.push_back({l, 0});
    }
    for (int i = 0; i < m; i++) {
        cin >> f;
        v.push_back({f, 1});
    }
    v.push_back({-INFL, 0});
    v.push_back({INFL, 0});
    sort(v.begin(), v.end());
    ll ans = 0;
    // get prefix
    for (int i = 0; i < n + m + 1; i++) {
        auto &[x, tp] = v[i];
        if (!tp) continue;
        pref[i] = pref[i - 1] + x - v[i - 1].fi;
    }
    // go backwards
    ll suf = 0, mn = INF;
    for (int i = n + m; i >= 0; i--) {
        auto &[x, tp] = v[i];
        if (!tp) {
            if (mn != INF) ans += mn;
            mn = INF;
            suf = 0;
            continue;
        }
        if (!v[i + 1].se) mn = min(mn, pref[i]);
        suf += v[i + 1].fi - x;
        mn = min(mn, suf + pref[i - 1]);

        // cout << i << " " << ans << " " << suf << " " << pref[i - 1] << " wtf\n";
    }
    cout << ans << "\n";
    return 0;
}