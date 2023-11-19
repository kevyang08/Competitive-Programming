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
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int last = a[n];
        for (int i = n - 1; i > 0; i--) {
            if (a[i] <= last) {
                last = a[i];
                continue;
            }
            ans += a[i]/last - 1;
            if (a[i]%last != 0) {
                int temp = last;
                if (a[i]%temp >= (temp + a[i]%temp)/2) last = a[i]%temp;
                else last = (temp + a[i]%temp)/2;
                last = max(last, a[i]/(a[i]/temp + 1));
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
