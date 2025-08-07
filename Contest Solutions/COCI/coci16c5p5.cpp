#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, q, l, r, a[500001], bit[500001], ans[500001], idx = 0;
vector<tuple<int, int, int>> vq;
map<int, int> mdx, mpv, bruh;
void update(int x, int v) {
    for (; x <= n; x += x & -x) bit[x] += v;
}
int query(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) res += bit[x];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        vq.push_back({r, l, i});
    }
    sort(vq.begin(), vq.end());
    for (auto &[r, l, i] : vq) {
        // cout << r << " " << l << " " << i << " bruh\n";
        while (idx < r) {
            ++idx;
            if (mdx.find(a[idx]) == mdx.end()) {
                mdx[a[idx]] = idx;
                continue;
            }
            if (bruh.find(a[idx]) != bruh.end()) update(bruh[a[idx]], 1);
            if (mpv.find(a[idx]) != mpv.end()) {
                update(mpv[a[idx]], -2);
                bruh[a[idx]] = mpv[a[idx]];
            }
            update(mdx[a[idx]], 1);
            mpv[a[idx]] = mdx[a[idx]];
            mdx[a[idx]] = idx;
        }
        // cout << query(r) << " " << query(l - 1) << " what\n";
        ans[i] = query(r) - query(l - 1);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}