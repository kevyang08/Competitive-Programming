#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, q, p[500001], a[500001], v, x, op;
ll tot[500001];
double res(int x) {
    double res = tot[x];
    ll thing = 0;
    int i = 1, c = p[x];
    while (c && i < 66 && res < a[x]) {
        thing *= 2;
        if (thing > INFL) break;
        if (tot[c] < a[c]) thing += a[c] - tot[c];
        else {
            if (tot[c] - a[c] > thing) {
                res += ((double)tot[c] - a[c] - thing)/(1LL << min(i, 62))/(1LL << max(0, i - 62));
                thing = 0;
            }
            else thing -= tot[c] - a[c];
        }
        c = p[c];
        ++i;
    }
    return min(res, (double)a[x]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        cin >> op >> x;
        if (op == 1) {
            cin >> v;
            tot[x] += v;
        }
        else cout << setprecision(6) << res(x) << "\n";
    }
    return 0;
}