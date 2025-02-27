#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6 + 1, M = 1e6 + 3;

int q, idx, cur = 0;
char op;
ll s[N], t[N], st[4 * N], lazy[4 * N], ans = 0;
multiset<int> times;
void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = l;
        return;
    }
    int m = (l + r)/2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
void pushdown(int l, int r, int idx) {
    st[idx] += lazy[idx];
    if (l != r) {
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
    }
    lazy[idx] = 0;
}
void update(int l, int r, int ql, int qr, int v, int idx) {
    if (lazy[idx]) pushdown(l, r, idx);
    if (ql <= l && r <= qr) {
        st[idx] += v;
        if (l != r) {
            lazy[2 * idx] += v;
            lazy[2 * idx + 1] += v;
        }
        return;
    }
    if (l > qr || r < ql) return;
    int m = (l + r)/2;
    update(l, m, ql, qr, v, 2 * idx);
    update(m + 1, r, ql, qr, v, 2 * idx + 1);
    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
ll query(int l, int r, int ql, int qr, int idx) {
    if (lazy[idx]) pushdown(l, r, idx);
    if (ql <= l && r <= qr) return st[idx];
    if (l > qr || r < ql) return 0;
    int m = (l + r)/2;
    return max(query(l, m, ql, qr, 2 * idx), query(m + 1, r, ql, qr, 2 * idx + 1));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    build(0, N - 1, 1);
    times.insert(0);
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == 'A') {
            ++cur;
            cin >> s[cur] >> t[cur];
            s[cur] = (s[cur] + ans)%M, t[cur] = (t[cur] + ans)%M;
            update(0, N - 1, 0, s[cur] - 1, t[cur], 1);
            times.insert(s[cur] - 1);
        }
        else {
            cin >> idx;
            idx = (idx + ans)%M;
            update(0, N - 1, 0, s[idx] - 1, -t[idx], 1);
            times.extract(s[idx] - 1);
        }
        int mx = *times.rbegin();
        ans = query(0, N - 1, 0, mx, 1);
        cout << ans << "\n";
    }
    return 0;
}