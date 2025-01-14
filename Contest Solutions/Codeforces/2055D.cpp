#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, l, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> l;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int idx = 1, o = 0, pos = k, ans = a[1];
        while (pos < l) {
            while (pos < l && idx < n && a[idx + 1] - ans - o <= pos) {
                int tmp = -1;
                if (a[idx + 1] > pos) tmp = pos;
                else tmp = min(pos, a[idx + 1] + ans);
                pos = tmp + k;
                ++idx;
            }
            if (pos >= l) break;
            if (o) ++ans, o = 0, ++pos;
            if (idx == n) ans += l - pos, pos = l;
            else {
                if ((a[idx + 1] - ans - pos) & 1) o = 1;
                int d = (a[idx + 1] - ans - pos)/2;
                ans += d;
                pos += d + k;
                ++idx;
            }
            if (pos >= l) break;
        }
        cout << 2 * ans + o << "\n";
    }
    return 0;
}