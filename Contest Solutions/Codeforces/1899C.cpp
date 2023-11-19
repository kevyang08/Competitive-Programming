#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> a[1];
        int ans = a[1], sum = a[1];
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            if (sum <= 0 || abs(a[i - 1])%2 == abs(a[i])%2) sum = a[i];
            else sum += a[i];
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
    return 0;
}
