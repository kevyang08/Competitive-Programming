#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        if (x && y || x == 0 && y == 0 || (n - 1)%max(x, y) != 0) cout << -1 << "\n";
        else {
            for (int i = 2; i <= n; i += max(x, y)) for (int j = 0; j < max(x, y); j++) cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}
