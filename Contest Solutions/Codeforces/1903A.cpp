#include <bits/stdc++.h>
using namespace std;
 
int t, n, k, a[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        bool thing = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i - 1] > a[i]) thing = false;
        }
        cout << (k > 1 || thing ? "YES" : "NO") << "\n";
    }
    return 0;
}
