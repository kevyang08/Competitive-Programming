#include <bits/stdc++.h>
using namespace std;

int n, arr[200], dp[200][200];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    while (n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 2; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                int mx = 0;
                for (int k = j + 1; k < j + i; k++) mx = max(mx, arr[j] + arr[k] + arr[j + i] + dp[j][k] + dp[k][j + i]);
                dp[j][j + i] = mx;
            }
        }
        cout << dp[0][n - 1] << "\n";
        cin >> n;
    }
}
