#include <bits/stdc++.h>
using namespace std;

const int sz = 500;

int n, q, a[200500], op, l, r, x, u, v, mo[sz][200500];
void update(int pr, int cr, int idx) {
    idx /= sz;
    for (int i = 1; i * i <= pr; i++) if (pr%i == 0) {
        mo[idx][i]--;
        if (i * i != pr) mo[idx][pr/i]--;
    }
    for (int i = 1; i * i <= cr; i++) if (cr%i == 0) {
        mo[idx][i]++;
        if (i * i != cr) mo[idx][cr/i]++;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) update(0, a[i], i);
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            int s = l/sz, e = r/sz, ans = 0;
            for (int i = s; i <= e; i++) ans += mo[i][x];
            for (int i = s * sz; i < l; i++) if (a[i] && a[i]%x == 0) ans--;
            for (int i = (e + 1) * sz - 1; i > r; i--) if (a[i] && a[i]%x == 0) ans--;
            cout << ans << "\n";
        }
        else {
            cin >> u >> v;
            update(a[u], v, u);
            a[u] = v;
        }
    }
    return 0;
}
