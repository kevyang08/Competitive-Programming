#include <bits/stdc++.h>
using namespace std;

int t, n, k, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> dp(k + 1, 0x3f3f3f3f);
        dp[0] = 0;
        while (n--) {
            cin >> a >> b;
            if (a > b) swap(a, b);
            vector<int> c(k + 1, 0x3f3f3f3f);
            c[0] = 0;
            int idx = 1;
            while (idx <= k && a > 0 && b > 0) {
                c[idx] = c[idx - 1] + a;
                --b;
                if (a > b) swap(a, b); 
                ++idx;
            }
            if (!a && idx <= k) c[idx] = c[idx - 1], ++idx;
            for (int i = k - 1; i >= 0; i--) {
                for (int j = 1; j < idx && i + j <= k; j++) dp[i + j] = min(dp[i + j], dp[i] + c[j]);
            }
        }
        cout << (dp[k] != 0x3f3f3f3f ? dp[k] : -1) << "\n";
    }
    return 0;
}