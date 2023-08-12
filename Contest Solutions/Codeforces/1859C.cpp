#include <bits/stdc++.h>
using namespace std;
 
int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int sum = 0, mx = 0;
            for (int j = 1; j <= n; j++) {
                if (j < i) {
                    sum += j * j;
                    mx = max(mx, j * j);
                }
                else {
                    sum += j * (n - j + i);
                    mx = max(mx, j * (n - j + i));
                }
            }
            ans = max(ans, sum - mx);
        }
        cout << ans << "\n";
    }
    return 0;
}
