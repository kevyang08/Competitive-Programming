#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 1e9 + 7;

int t, n, m, b;
ll a[300005], mn[1200005], cnt[1200005];
void update(int l, int r, int i, ll v, ll c, int idx) {
    if (l == r) {
        if (v < mn[idx]) {
            mn[idx] = v;
            cnt[idx] = c;
        }
        else if (v == mn[idx]) cnt[idx] = (cnt[idx] + c)%M;
        return;
    }
    int m = (l + r)/2;
    if (i > m) update(m + 1, r, i, v, c, 2 * idx + 1);
    else update(l, m, i, v, c, 2 * idx);
    mn[idx] = min(mn[2 * idx], mn[2 * idx + 1]);
    cnt[idx] = 0;
    if (mn[idx] == mn[2 * idx]) cnt[idx] = (cnt[idx] + cnt[2 * idx])%M;
    if (mn[idx] == mn[2 * idx + 1]) cnt[idx] = (cnt[idx] + cnt[2 * idx + 1])%M;
}
pair<ll, ll> query(int l, int r, int ql, int qr, int idx) {
    if (l > qr || r < ql) return {INFL, 0};
    if (ql <= l && r <= qr) return {mn[idx], cnt[idx]};
    int m = (l + r)/2;
    pair<ll, ll> rl = query(l, m, ql, qr, 2 * idx), rr = query(m + 1, r, ql, qr, 2 * idx + 1);
    if (rl.first == rr.first) return {rl.first, (rl.second + rr.second)%M};
    else if (rl.first > rr.first) return rr;
    return rl;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n * 4; i++) mn[i] = INFL, cnt[i] = 0;
        for (int k = 1; k <= m; k++) {
            // cout << k << " bruh\n";

            cin >> b;
            for (int i = 1, j = 0; i <= n; i++) {
                while (j < i && a[i] - a[j] > b) ++j;
                if (j == i) continue;
                if (!j) {
                    pair<ll, ll> tmp = query(1, n, 1, i - 1, 1);
                    update(1, n, i, m - k, 1 + (tmp.first == 0 ? tmp.second : 0), 1);
                }
                else {
                    pair<ll, ll> tmp = query(1, n, j, i - 1, 1);
                    update(1, n, i, tmp.first + m - k, tmp.second, 1);
                }

                // cout << query(1, n, i, i, 1).first << " ";
            }

            // cout << "debug\n";
        }
        pair<ll, ll> ans = query(1, n, n, n, 1);
        if (ans.first == INFL) cout << "-1\n";
        else cout << ans.first << " " << ans.second << "\n";
        // else cout << ans.first << "\n";
    }
    return 0;
}