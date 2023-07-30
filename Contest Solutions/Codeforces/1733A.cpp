#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, a, m[100]{0};
        long long ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a;
            m[i%k] = max(a, m[i%k]);
        }
        for (int i = 0; i < k; i++) ans += m[i];
        cout << ans << "\n";
    }
    return 0;
}
