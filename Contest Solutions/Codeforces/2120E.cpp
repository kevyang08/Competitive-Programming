#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k;
vector<int> a;
ll check(ll m) {
    ll tmp = m, cur = a.back(), cnt = 1, res = -m * k, lc = -1, llc = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (tmp > (cur - a[i]) * cnt) {
            tmp -= (cur - a[i]) * cnt;
            res += (cur * (cur + 1)/2 - (ll)a[i] * (a[i] + 1)/2) * cnt;
            cur = a[i];
            ++cnt;
        }
        else break;
    }
    if (tmp) {
        tmp = min(cur * cnt, tmp);
        ll last = cur - tmp/cnt;
        res += (cur * (cur + 1)/2 - last * (last + 1)/2) * cnt;
        lc = last;
        if (tmp == cnt * (cur - last)) ++lc;
        else res += (tmp%cnt) * last;
    }
    tmp = m, cur = a.front(), cnt = 1;
    for (int i = 1; i < n; i++) {
        if (tmp > (a[i] - cur) * cnt) {
            tmp -= (a[i] - cur) * cnt;
            res -= ((ll)a[i] * (a[i] + 1)/2 - cur * (cur + 1)/2) * cnt;
            cur = a[i];
            ++cnt;
        }
        else break;
    }
    if (tmp) {
        ll last = cur + tmp/cnt;
        res -= (last * (last + 1)/2 - cur * (cur + 1)/2) * cnt;
        llc = last;
        if (tmp%cnt) {
            ++llc;
            res -= (tmp%cnt) * llc;
        }
    }
    return llc + k >= lc ? 0 : res;
}
void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0, l = 0, r = INFL, tot = 0;
    for (int i = 0; i < n; i++) tot += (ll)a[i] * (a[i] + 1)/2;
    if (n == 1) {
        cout << tot << "\n";
        return;
    }
    sort(a.begin(), a.end());
    while (l < r) {
        ll m = (l + r + 1)/2, thing = check(m);
        if (thing) l = m, ans = thing;
        else r = m - 1;
    }
    cout << tot - ans << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}