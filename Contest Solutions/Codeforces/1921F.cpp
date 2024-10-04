#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 400;

int t, n, q, s, d, k;
ll a[100001], psa[sz + 1][100001], pss[sz + 1][100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 1; j <= sz; j++) {
                psa[j][i] = a[i];
                pss[j][i] = a[i] * (i/j + (i%j ? 1 : 0));
                if (i >= j) {
                    psa[j][i] += psa[j][i - j];
                    pss[j][i] += pss[j][i - j];
                }
            }
        }
        while (q--) {
            cin >> s >> d >> k;
            ll ans = 0;
            if (d > sz) for (int i = 1; i <= k; i++) ans += a[s + d * (i - 1)] * i;
            else ans = pss[d][s + d * (k - 1)] - pss[d][max(s - d, 0)] - (psa[d][s + d * (k - 1)] - psa[d][max(s - d, 0)]) * max(s/d - (s%d ? 0 : 1), 0);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}