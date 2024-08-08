#include <bits/stdc++.h>
using namespace std;

int t, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        int ans = a + b, mnb = b;
        for (int i = 2; i <= 50000; i++) {
            if (i <= b && b/i + (b%i ? 1 : 0) < mnb) mnb = b/i + (b%i ? 1 : 0);
            ans = min(ans, i - 1 + a/i + (a%i ? 1 : 0) + mnb);
        }
        cout << ans << "\n";
    }
    return 0;
}