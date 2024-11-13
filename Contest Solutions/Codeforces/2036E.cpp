#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, q, m, r, c;
char o;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> t;
    // while (t--) {
        cin >> n >> k >> q;
        vector<vector<int>> a(n + 1, vector<int>(k + 1));
        vector<map<int, int>> mpl(k + 1), mph(k + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                cin >> a[i][j];
                a[i][j] |= a[i - 1][j];
                mpl[j].emplace(a[i][j], i);
                mph[j][a[i][j]] = i;
            }
        }
        while (q--) {
            int lo = 1, hi = n;
            cin >> m;
            while (m--) {
                cin >> r >> o >> c;
                if (o == '<') {
                    if (mph[r].lower_bound(c) == mph[r].begin()) lo = INF;
                    else hi = min(hi, (--mph[r].lower_bound(c)) -> second);
                }
                else {
                    if (mpl[r].upper_bound(c) == mpl[r].end()) lo = INF;
                    else lo = max(lo, mpl[r].upper_bound(c) -> second);
                }
            }
            cout << (lo > hi ? -1 : lo) << "\n";
        }
    // }
    return 0;
}