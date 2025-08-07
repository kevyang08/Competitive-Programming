#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int sz = 520;

int n, k[200000], q, x, v, nxt[200000], cnt[200000], op;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> k[i];
    for (int i = n - 1; i >= 0; i--) {
        if (i + k[i] >= n || (i + k[i])/sz != i/sz) {
            cnt[i] = 1;
            nxt[i] = i + k[i];
            continue;
        }
        nxt[i] = nxt[i + k[i]];
        cnt[i] = cnt[i + k[i]] + 1;
    }
    cin >> q;
    while (q--) {
        cin >> op >> x;
        if (op == 1) {
            int ans = 0;
            while (x < n) {
                ans += cnt[x];
                x = nxt[x];
            }
            cout << ans << "\n";
            continue;
        }
        cin >> v;
        k[x] = v;
        if (x + v >= n || (x + v)/sz != x/sz) {
            cnt[x] = 1;
            nxt[x] = x + v;
        }
        else {
            nxt[x] = nxt[x + v];
            cnt[x] = cnt[x + v] + 1;
        }
        for (int i = x - 1; i >= 0 && i/sz == x/sz; i--) {
            if (i + k[i] >= n || (i + k[i])/sz != i/sz) continue;
            nxt[i] = nxt[i + k[i]];
            cnt[i] = cnt[i + k[i]] + 1;
        }
    }
    return 0;
}