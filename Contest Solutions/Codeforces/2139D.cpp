#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int t, n, q, a[500001], l, r, ans[500001], bit[500001], bit2[500001];
void update(int i) {
    for (; i <= n; i += (i & -i)) ++bit[i];
}
int query(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}
void update2(int i, int v) {
    for (; i > 0; i -= (i & -i)) bit2[i] = max(bit2[i], v);
}
int query2(int i) {
    int res = 0;
    for (; i <= n; i += (i & -i)) res = max(res, bit2[i]);
    return res;
}
void solve() {
    cin >> n >> q;
    fill(bit, bit + n + 1, 0);
    fill(bit2, bit2 + n + 1, 0);
    vector<tuple<int, int, int>> vq;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        vq.push_back({r, l, i});
    }
    sort(vq.begin(), vq.end());
    stack<int> st;
    for (int i = 1, j = 0; i <= n; i++) {
        int pr = 0, ppr = query2(a[i] + 1);
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        if (!st.empty()) pr = st.top();
        st.push(i);
        update2(a[i], pr);
        if (ppr) update(ppr);
        while (j < q && get<0>(vq[j]) == i) {
            auto &[qr, ql, idx] = vq[j];
            ans[idx] = query(qr) - query(ql - 1);
            ++j;
        }
    }
    for (int i = 1; i <= q; i++) cout << (!ans[i] ? "YES\n" : "NO\n");
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