#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[3001], dp[3001][3001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < n; i++)
        for (int j = 1; j + i <= n; j++)
            dp[j][j + i] = max(arr[j + i] - arr[j - 1] - dp[j + 1][j + i], arr[j + i] - arr[j + i - 1] + arr[j + i - 1] - arr[j - 1] - dp[j][j + i - 1]);
    cout << dp[1][n] - arr[n] + dp[1][n] << "\n";
}