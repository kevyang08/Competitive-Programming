#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, ans = 0;
ll psa[805][405];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> psa[i][j];
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    for (int j = 1; j < m; j++) {
        for (int l = j, r = j + 1; r <= m; l++, r += 2) {
            map<ll, int> st;
            st[0] = 0;
            for (int i = 1; i <= n; i++) {
                ll tl = psa[i][l] - psa[i][j - 1], tr = psa[i][r] - psa[i][l];
                // cout << i << " " << j << " " << l << " " << r << " bruh\n";
                if (st.find(tr - tl) != st.end()) ans = max(ans, (r - j + 1) * (i - st[tr - tl]));
                else st[tr - tl] = i;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}