#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353, MAXN = 200001;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, arr[MAXN];
    long long dp[MAXN], psa[MAXN], t = 0;
    cin >> n;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        t += (x - arr[i - 1])%MOD;
        int l = 0, r = i - 1;
        while (l < r) {
            int m = (l + r + 1)/2;
            if (arr[m] > y) r = m - 1;
            else l = m;
        }
        dp[i] += (psa[i - 1] - psa[l] + x - y)%MOD;
        psa[i] = dp[i] + psa[i - 1];
        if (s) t += dp[i];
        arr[i] = x;
        t %= MOD;
    }
    cout << (t + 1)%MOD << "\n";
    return 0;
}
