#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int M = 998244353;
// const int M = 1e9 + 7;

int t, n, a[300005];
ll st[1200005], lz[1200005], c[300005];
void build(int l, int r, int idx) {
    st[idx] = 0; lz[idx] = 1;
    if (l == r) return;
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
}
void pushdown(int l, int r, int idx) {
    if (lz[idx] == 1) return;
    (st[idx] *= lz[idx]) %= M;
    if (l != r) {
        (lz[2 * idx] *= lz[idx]) %= M;
        (lz[2 * idx + 1] *= lz[idx]) %= M;
    }
    lz[idx] = 1;
}
void mul(int l, int r, int ql, int qr, int idx) {
    pushdown(l, r, idx);
    if (ql <= l && r <= qr) {
        (lz[idx] *= 2) %= M;
        pushdown(l, r, idx);
        return;
    }
    if (l > qr || r < ql) return;
    int m = (l + r)/2;
    mul(l, m, ql, qr, 2 * idx);
    mul(m + 1, r, ql, qr, 2 * idx + 1);
    st[idx] = (st[2 * idx] + st[2 * idx + 1])%M;
}
void update(int l, int r, int ql, int idx, int v) {
    pushdown(l, r, idx);
    if (l == r) {
        (st[idx] += v) %= M;
        return;
    }
    int m = (l + r)/2;
    if (m < ql) update(m + 1, r, ql, 2 * idx + 1, v);
    else update(l, m, ql, 2 * idx, v);
    st[idx] = (st[2 * idx] + st[2 * idx + 1])%M;
}
ll query(int l, int r, int ql, int qr, int idx) {
    pushdown(l, r, idx);
    if (ql <= l && r <= qr) return st[idx];
    if (l > qr || r < ql) return 0;
    int m = (l + r)/2;
    return (query(l, m, ql, qr, 2 * idx) + query(m + 1, r, ql, qr, 2 * idx + 1))%M;
}
void solve() {
    ll ans = 0;
    stack<int> stk;
    map<int, int> mp;
    set<int> coords, sth;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        coords.insert(a[i]);
        while (!stk.empty() && stk.top() <= a[i]) stk.pop();
        stk.push(a[i]);
        c[i] = 0;
    }
    for (int i = 1; !coords.empty(); i++) {
        mp[*coords.begin()] = i;
        coords.erase(coords.begin());
    }
    while (!stk.empty()) {
        sth.insert(stk.top());
        stk.pop();
    }
    build(1, n, 1);
    for (int i = n; i > 0; i--) {
        if (sth.find(a[i]) != sth.end()) {
            int v = query(1, n, mp[a[i]], mp[a[i]], 1);
            if (*sth.begin() != a[i]) {
                int p = mp[*(--sth.lower_bound(a[i]))];
                (v += query(1, n, p, p, 1)) %= M;
            }
            else ++v;
            update(1, n, mp[a[i]], 1, v);
            c[i] = v;
        }
        if (a[i] != *sth.rbegin()) mul(1, n, mp[*sth.upper_bound(a[i])], n, 1);
    }
    sth.clear();
    for (int i = n; i > 0; i--) {
        while (!stk.empty() && stk.top() <= a[i]) stk.pop();
        stk.push(a[i]);
    }
    while (!stk.empty()) {
        sth.insert(stk.top());
        stk.pop();
    }
    build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        if (sth.find(a[i]) != sth.end()) {
            int v = query(1, n, mp[a[i]], mp[a[i]], 1);
            if (*sth.begin() != a[i]) {
                int p = mp[*(--sth.lower_bound(a[i]))];
                (v += query(1, n, p, p, 1)) %= M;
            }
            else ++v;
            if (a[i] == *sth.rbegin()) (ans += (v * c[i])%M) %= M;
            else update(1, n, mp[a[i]], 1, v);
        }
        if (a[i] != *sth.rbegin()) mul(1, n, mp[*sth.upper_bound(a[i])], n, 1);
    }
    cout << ans << "\n";
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