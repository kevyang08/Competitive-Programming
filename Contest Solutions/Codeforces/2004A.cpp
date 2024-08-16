#include <bits/stdc++.h>
using namespace std;

int t, n, x[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> x[i];
        cout << (n == 2 && x[1] + 1 < x[2] ? "YES\n" : "NO\n");
    }
    return 0;
}