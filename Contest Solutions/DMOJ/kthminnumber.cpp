#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, q, a, l, r, k, ans = 0;
set<int> v;
map<int, vector<int>> tmp;
map<int, int> id;
vector<int> st[800005];
void build(int l, int r, int idx) {
    if (l == r) {
        for (int i : tmp[id[l]]) st[idx].push_back(i);
        return;
    }
    int m = (l + r)/2, lp = 0, rp = 0;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    while (lp < st[2 * idx].size() || rp < st[2 * idx + 1].size()) {
        if (rp >= st[2 * idx + 1].size() || lp < st[2 * idx].size() && st[2 * idx][lp] <= st[2 * idx + 1][rp]) st[idx].push_back(st[2 * idx][lp++]);
        else st[idx].push_back(st[2 * idx + 1][rp++]);
    }
}
int query(int l, int r, int ql, int qr, int k, int idx) {

    // cout << l << " " << r << " " << idx << " bruh\n";

    if (l == r) return id[l];
    int m = (l + r)/2;
    if (st[2 * idx].empty()) return query(m + 1, r, ql, qr, k, 2 * idx + 1);
    auto lo = lower_bound(st[2 * idx].begin(), st[2 * idx].end(), ql), hi = --upper_bound(st[2 * idx].begin(), st[2 * idx].end(), qr);
    int ln = hi - lo + 1;

    // cout << lo << " " << hi << " whatwhat\n";


    if (ln < k) return query(m + 1, r, ql, qr, k - ln, 2 * idx + 1);
    return query(l, m, ql, qr, k, 2 * idx);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v.insert(a);
        tmp[a].push_back(i);
    }
    int c = 0;
    for (int i : v) id[++c] = i;
    build(1, n, 1);
    while (q--) {
        cin >> l >> r >> k;
        l ^= ans, r ^= ans, k ^= ans;
        ans = query(1, n, l, r, k, 1);
        cout << ans << "\n";
    }
    return 0;
}