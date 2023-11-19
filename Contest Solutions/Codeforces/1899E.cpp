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
        int ans = 0, cnt = 0, mn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
            if (a[i - 1] > a[i]) cnt++;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == mn) break;
            ans++;
            if (a[i] > a[i + 1]) cnt--;
        }
        cout << (cnt ? -1 : ans) << "\n";
    }
    return 0;
}
