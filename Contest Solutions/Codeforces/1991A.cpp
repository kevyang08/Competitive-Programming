#include <bits/stdc++.h>
using namespace std;

int t, n, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int mx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (i%2) mx = max(mx, a);
        }
        cout << mx << "\n";
    }
    return 0;
}