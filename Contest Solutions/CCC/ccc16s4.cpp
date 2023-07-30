#include <bits/stdc++.h>
using namespace std;

int n, arr[401], mx = 0;
bool dp[401][401];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        dp[i][i] = true;
    }
    for (int k = 1; k < n; k++) {
        for (int i = 1; i + k <= n; i++) {
            for (int j = i; j < i + k; j++) if (dp[i][j] && dp[j + 1][i + k] && arr[j] - arr[i - 1] == arr[i + k] - arr[j]) dp[i][i + k] = true;
            for (int l = i, r = i + k; l + 1 < r;) {
                if (dp[i][l] && dp[r][i + k] && dp[l + 1][r - 1] && arr[l] - arr[i - 1] == arr[i + k] - arr[r - 1]) {
                    dp[i][i + k] = true;
                    break;
                }
                else if (arr[l] - arr[i - 1] > arr[i + k] - arr[r - 1]) r--;
                else l++;
            }
        }
    }
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) if (dp[i][j]) mx = max(mx, arr[j] - arr[i - 1]);
    cout << mx << "\n";
}
