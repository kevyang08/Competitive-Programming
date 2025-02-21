#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int sz = 1000;

int n, q, l, r, a[1000001], op, v, cnt[1001][501], thing[1001];
void update(int idx) {
    for (int i = 1; i <= 500; i++) cnt[idx][i] = 0;
    cnt[idx][thing[idx]] = sz;
    for (int i = idx * sz; i < idx * sz + sz; i++) a[i] = thing[idx];
    thing[idx] = 0;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ++cnt[i/sz][a[i]];
    }
    while (q--) {
        cin >> op >> l >> r >> v;
        int s = l/sz, e = r/sz;
        if (op == 1) {
            for (int i = s + 1; i < e; i++) thing[i] = v;
            if (thing[s]) update(s);
            for (int i = l; i < min(r + 1, s * sz + sz); i++) {
                --cnt[s][a[i]];
                ++cnt[s][v];
                a[i] = v;
            }
            if (s != e) {
                if (thing[e]) update(e);
                for (int i = e * sz; i <= r; i++) {
                    --cnt[e][a[i]];
                    ++cnt[e][v];
                    a[i] = v;
                }
            }
        }
        else {
            int res = 0;
            for (int i = s + 1; i < e; i++) {
                if (thing[i] == v) res += sz;
                else if (!thing[i]) res += cnt[i][v];
            }
            if (thing[s]) update(s);
            for (int i = l; i < min(r + 1, s * sz + sz); i++) res += (a[i] == v);
            if (e != s) {
                if (thing[e]) update(e);
                for (int i = e * sz; i <= r; i++) res += (a[i] == v);
            }
            cout << res << "\n";
        }
    }
    return 0;
}