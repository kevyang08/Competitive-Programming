#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

const int sz = 250;

int n, m, q, l[200005], a[200005], ans[605], x, y, op, off[200005], bruh[200005];
vector<int> v[200005], idx[200005];
vector<int> s[200005], e[200005];
pair<int, int> mp[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (idx[l[i]].empty() || idx[l[i]].back() != i/sz) {
            s[l[i]].push_back(v[l[i]].size());
            e[l[i]].push_back(v[l[i]].size());
            idx[l[i]].push_back(i/sz);
        }
        e[l[i]].back() = v[l[i]].size();
        ans[i/sz] += a[i];
        mp[i] = {l[i], v[l[i]].size()};
        v[l[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++) bruh[i] = v[i].size();
    while (q--) {
        cin >> op >> x;
        if (op == 1) {
            cin >> y;
            int ql = x/sz, qr = y/sz, cur = 0;
            for (int i = ql; i <= qr; i++) cur += ans[i];
            // cout << cur << " bruh\n";
            for (int i = max(ql * sz, 1); i < x; i++) {
                auto [ll, ldx] = mp[i];
                (ldx += bruh[ll] - off[ll]) %= bruh[ll];
                cur -= a[v[ll][ldx]];
            }
            // cout << cur << " wtf\n";
            for (int i = y + 1; i <= min(n, qr * sz + sz - 1); i++) {
                auto [ll, ldx] = mp[i];
                (ldx += bruh[ll] - off[ll]) %= bruh[ll];
                cur -= a[v[ll][ldx]];
            }
            cout << cur << "\n";
        }
        else {
            (off[x] += 1) %= bruh[x];
            int thing = idx[x].size();
            for (int i = 0; i < thing; i++) {
                ans[idx[x][i]] -= a[v[x][e[x][i]]];
                (s[x][i] += bruh[x] - 1) %= bruh[x];
                (e[x][i] += bruh[x] - 1) %= bruh[x];
                ans[idx[x][i]] += a[v[x][s[x][i]]];
            }
        }
    }
    return 0;
}