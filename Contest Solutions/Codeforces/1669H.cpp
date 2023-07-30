#include <bits/stdc++.h>
using namespace std;
 
int t, n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int ans = 0, arr[31], a;
        memset(arr, 0, sizeof(arr));
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a;
            for (int j = 0; j < 31; j++) if (a & (1 << j)) arr[j]++;
        }
        for (int i = 30; i >= 0; i--) {
            if (n - arr[i] <= k) {
                k -= n - arr[i];
                arr[i] = n;
            }
            if (arr[i] == n) ans |= (1 << i);
        }
        cout << ans << "\n";
    }
}
