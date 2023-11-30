#include <bits/stdc++.h>
using namespace std;
 
int n, q;
long long k, a[100005], arr[100005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        cin >> k;
        long long ans = 0;
        for (int i = 1; i <= n; i++) arr[i] = a[i];
        for (int j = 62; j >= 0; j--) {
            long long cur = (1LL << j), tmp = 0;
            for (int i = 1; i <= n; i++) {
                tmp += cur - min(arr[i], cur);
                if (tmp > k) break;
            }
            if (tmp <= k) {
                k -= tmp;
                ans += cur;
                for (int i = 1; i <= n; i++) if (arr[i] <= cur) arr[i] = 0;
            }
            for (int i = 1; i <= n; i++) arr[i] &= cur - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
