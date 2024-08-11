#include <bits/stdc++.h>
using namespace std;

int t, n, q, a, p[100001], pos[100001], sz[100001], x, y;
bool v[100001];
bool check(int i) {
    return (pos[i << 1] == pos[i] + 1 && pos[i << 1 | 1] == pos[i] + sz[i] + 1) || (pos[i << 1 | 1] == pos[i] + 1 && pos[i << 1] == pos[i] + sz[i] + 1);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        fill(v, v + n + 1, true);
        sz[1] = ((n - 1) >> 1);
        for (int i = 2; i <= n; i++) sz[i] = ((sz[i >> 1] - 1) >> 1);
        for (int i = 2; i <= n; i++) cin >> a;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        for (int i = (n >> 1); i > 0; i--) v[i] = check(i) & v[i << 1] & v[i << 1 | 1];
        while (q--) {
            cin >> x >> y;
            int a = p[x], b = p[y];
            swap(pos[p[x]], pos[p[y]]);
            swap(p[x], p[y]);
            x = a, y = b;
            if (x <= (n >> 1)) v[x] = check(x) & v[x << 1] & v[x << 1 | 1];
            if (y <= (n >> 1)) v[y] = check(y) & v[y << 1] & v[y << 1 | 1];
            x >>= 1;
            if (x) v[x] = check(x) & v[x << 1] & v[x << 1 | 1];
            y >>= 1;
            if (y) v[y] = check(y) & v[y << 1] & v[y << 1 | 1];
            while (x >>= 1) v[x] = check(x) & v[x << 1] & v[x << 1 | 1];
            while (y >>= 1) v[y] = check(y) & v[y << 1] & v[y << 1 | 1];
            cout << (v[1] ? "YES\n" : "NO\n");
        }
    }
    return 0;
}