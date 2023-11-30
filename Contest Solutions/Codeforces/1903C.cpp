#include <bits/stdc++.h>
using namespace std;
 
int t, n;
long long ans = 0, a[100005], arr[100005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += i * a[i];
            arr[i] = a[i];
        }
        arr[n + 1] = 0;
        for (int i = n; i > 0; i--) {
            arr[i] += arr[i + 1];
            if (arr[i] < 0 && i > 1) ans -= arr[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
 
/*
go backwards
keep running suffix sum
*/
