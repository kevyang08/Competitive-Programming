#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, m;
string s, b = "narek";
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    set<char> st(b.begin(), b.end());
    cin >> t;
    while (t--) {
        cin >> n >> m;
        s.resize(n);
        int mx = 0;
        vector<int> dp(5);
        for (int i = 1; i < 5; i++) dp[i] = -0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            cin >> s;
            vector<int> idx(5);
            vector<int> d(5); // discarded
            iota(idx.begin(), idx.end(), 0);
            for (int j = 0; j < m; j++) {
                if (st.find(s[j]) == st.end()) continue;
                for (int k = 0; k < 5; k++) {
                    if (b[idx[k]%5] == s[j]) ++idx[k];
                    else ++d[k];
                }
            }
            vector<int> tmp(5);
            for (int i = 0; i < 5; i++) tmp[i] = dp[i];
            for (int k = 0; k < 5; k++) {
                // if (idx[k] - k + dp[k] <= d[k]) continue;
                tmp[idx[k]%5] = max(tmp[idx[k]%5], idx[k] - k - d[k] + dp[k]);
                mx = max(mx, idx[k] - k - d[k] - 2 * (idx[k]%5) + dp[k]);
            }
            for (int i = 0; i < 5; i++) dp[i] = tmp[i];

            // cout << i << " wtf\n";
            // for (int k = 0; k < 5; k++) cout << k << " " << tmp[k] << " bruh\n";
        }
        cout << mx << "\n";
    }
    return 0;
}