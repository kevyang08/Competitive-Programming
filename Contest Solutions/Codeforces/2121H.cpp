#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// note: forgot to increment old lazy max updates

int t, n, l[200005], r[200005], st[1600005], slz[1600005], mlz[1600005];
void build(int l, int r, int idx) {
    st[idx] = slz[idx] = mlz[idx] = 0;
    if (l == r) return;
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
}
void pushdown(int l, int r, int idx) {
    if (!mlz[idx]) return;
    st[idx] = max(st[idx] + slz[idx], mlz[idx]);
    if (l != r) {
        slz[2 * idx] += slz[idx]; slz[2 * idx + 1] += slz[idx];
        mlz[2 * idx] = max(mlz[2 * idx] + slz[idx], mlz[idx]); mlz[2 * idx + 1] = max(mlz[2 * idx + 1] + slz[idx], mlz[idx]);
    }
    mlz[idx] = slz[idx] = 0;
}
void update(int l, int r, int ql, int qr, int idx, int qt, int v) {
    pushdown(l, r, idx);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        if (!qt) {
            st[idx] += v;
            if (l != r) {
                slz[2 * idx] += v, mlz[2 * idx] += v;
                slz[2 * idx + 1] += v, mlz[2 * idx + 1] += v;
            }
        }
        else {
            st[idx] = max(st[idx], v);
            if (l != r) {
                mlz[2 * idx] = max(mlz[2 * idx], v);
                mlz[2 * idx + 1] = max(mlz[2 * idx + 1], v);
            }
        }
        return;
    }
    int m = (l + r)/2;
    update(l, m, ql, qr, 2 * idx, qt, v);
    update(m + 1, r, ql, qr, 2 * idx + 1, qt, v);
    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
int query(int l, int r, int ql, int qr, int idx) {
    pushdown(l, r, idx);
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return st[idx];
    int m = (l + r)/2;
    return max(query(l, m, ql, qr, 2 * idx), query(m + 1, r, ql, qr, 2 * idx + 1));
}
void solve() {
    map<int, int> mp;
    vector<int> c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        c.push_back(l[i]);
        c.push_back(r[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < 2 * n; i++) mp[c[i]] = i + 1;
    build(1, 2 * n, 1);
    for (int i = 0; i < n; i++) {
        update(1, 2 * n, mp[l[i]], mp[r[i]], 1, 0, 1);
        int mx = query(1, 2 * n, 1, mp[r[i]], 1);
        update(1, 2 * n, mp[r[i]], 2 * n, 1, 1, mx);
        cout << query(1, 2 * n, 1, 2 * n, 1) << " ";
    }
    cout << "\n";
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