#include <bits/stdc++.h>
using namespace std;

int t, n, p[51];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 3;
        for (int i = 1; i <= n; i++) p[i] = -1;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            if (p[p[i]] == i) ans = 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
