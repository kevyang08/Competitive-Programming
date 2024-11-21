#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, q, a, st[800010], mn[800010], mx[800010], b;
void update(int l, int r, int i, int v, int idx) {
    if (l == r) {
        mn[idx] = mx[idx] = v;
        return;
    }
    int m = (l + r)/2;
    if (i > m) update(m + 1, r, i, v, 2 * idx + 1);
    else update(l, m, i, v, 2 * idx);
    if (mx[2 * idx] > mn[2 * idx + 1]) {
        if (st[2 * idx] != INF || st[2 * idx + 1] != INF || mx[2 * idx + 1] > mn[2 * idx]) st[idx] = -1;
        else st[idx] = m;
    }
    // else if (st[2 * idx] == INF && st[2 * idx + 1] == INF) st[idx] = INF;
    else if (st[2 * idx] != INF || st[2 * idx + 1] != INF) {
        if (st[2 * idx] != INF && st[2 * idx + 1] != INF || mx[2 * idx + 1] > mn[2 * idx]) st[idx] = -1;
        else st[idx] = min(st[2 * idx], st[2 * idx + 1]);;
    }
    else st[idx] = INF;
    mn[idx] = mn[2 * idx];
    mx[idx] = mx[2 * idx + 1];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    memset(st, INF, sizeof(st));
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        update(1, n, i, a, 1);
    }
    // update(1, n + 1, n + 1, 0, 1);
    while (q--) {
        cin >> a >> b;
        update(1, n, a, b, 1);
        if (st[1] == INF) cout << "0\n";
        else if (st[1] == -1) cout << "-1\n";
        else cout << min(st[1], n - st[1]) << "\n";
    }
    return 0;
}