#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, k, a[100005], q, l, r, st[400005], lz[400005];
pair<int, int> ans[100005];
deque<int> dq[2];
vector<tuple<int, int, int>> vq;
void pushdown(int l, int r, int idx) {
    if (!lz[idx]) return;
    st[idx] += lz[idx];
    if (l != r) {
        lz[2 * idx] += lz[idx];
        lz[2 * idx + 1] += lz[idx];
    }
    lz[idx] = 0;
}
void update(int l, int r, int ql, int qr, int idx) {
    pushdown(l, r, idx);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ++lz[idx];
        pushdown(l, r, idx);
        return;
    }
    int m = (l + r)/2;
    update(l, m, ql, qr, 2 * idx);
    update(m + 1, r, ql, qr, 2 * idx + 1);
    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
int query(int l, int r, int ql, int qr, int idx) {
    pushdown(l, r, idx);
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return st[idx];
    int m = (l + r)/2;
    return max(query(l, m, ql, qr, 2 * idx), query(m + 1, r, ql, qr, 2 * idx + 1));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        vq.push_back({r, l, i});
    }
    sort(vq.begin(), vq.end());
    int i = 0, lo = 1;
    for (auto &[r, l, j] : vq) {
        while (i < r) {
            ++i;
            while (!dq[0].empty() && a[dq[0].back()] >= a[i]) dq[0].pop_back();
            dq[0].push_back(i);
            while (!dq[1].empty() && a[dq[1].back()] <= a[i]) dq[1].pop_back();
            dq[1].push_back(i);
            while (!dq[0].empty() && a[i] - k > a[dq[0].front()]) {
                lo = dq[0].front() + 1;
                if (!dq[1].empty() && dq[1].front() < lo) dq[1].pop_front();
                dq[0].pop_front();
            }
            while (!dq[1].empty() && a[i] + k < a[dq[1].front()]) {
                lo = dq[1].front() + 1;
                if (!dq[0].empty() && dq[0].front() < lo) dq[0].pop_front();
                dq[1].pop_front();
            }
            update(1, n, lo, i, 1);
        }
        int ll = l, rr = r, mx = query(1, n, l, r, 1);
        while (ll < rr) {
            int m = (ll + rr)/2;
            if (query(1, n, ll, m, 1) == mx) rr = m;
            else ll = m + 1;
        }
        ans[j] = {rr, rr + mx - 1};
    }
    for (int i = 1; i <= q; i++) cout << ans[i].fi << " " << ans[i].se << "\n";
    return 0;
}