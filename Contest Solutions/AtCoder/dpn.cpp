#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    long long arr[400][400], dp[400][400];
    for (int i = 0; i < n; i++) {cin >> arr[i][i];dp[i][i] = 0;}
    for (int k = 1; k < n; k++) {
    	for (int i = 0; i < n - k; i++) {
    		long long mn = 0x3f3f3f3f3f3f3f3f;
    		for (int j = 0; j < k; j++) mn = min(mn, dp[i][i + j] + arr[i][i + j] + dp[i + j + 1][i + k] + arr[i + j + 1][i + k]);
    		dp[i][i + k] = mn;
    		arr[i][i + k] = arr[i + 1][i + k] + arr[i][i];
    	}
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}
