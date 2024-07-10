#include <bits/stdc++.h>
using namespace std;

int t, n, b[100001], dp[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int mx = 0, mdx = 2;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            dp[i] = dp[i - 1];
            if (b[dp[i]] - i + dp[i] <= b[i]) dp[i] = i;
        }
        for (int i = 3; i <= n; i++) {
            mx = max(mx, b[mdx] + b[dp[mdx - 1]] + b[i] - i + dp[mdx - 1]);
            if (b[mdx] + b[dp[mdx - 1]] - i + dp[mdx - 1] <= b[i] + b[dp[i - 1]] - i + dp[i - 1]) mdx = i;
        }
        cout << mx << "\n";
    }
    return 0;
}