#include <bits/stdc++.h>
using namespace std;

int n, c, w, v, ans;
long long dp[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 1; i < 100001; i++) dp[i] = 0x3f3f3f3f;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        for (int j = 100000; j >= v; j--) dp[j] = min(dp[j], dp[j - v] + w);
    }
    for (int i = 1; i < 100001; i++) if (dp[i] <= c) ans = i;
    cout << ans << "\n";
}
