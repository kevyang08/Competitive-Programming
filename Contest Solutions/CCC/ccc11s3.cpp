#include <bits/stdc++.h>
using namespace std;

bool bruh(int m, int x, int y) {
    if (m < 0) return false;
    int p = pow(5, m);
    if (y/p == 1 && x/p == 2 || y/p == 0 && x/p > 0 && x/p < 4) return true;
    else if (y/p == 2 && x/p == 2 || y/p == 1 && (x/p == 1 || x/p == 3)) return bruh(m - 1, x%p, y%p);
    else return false;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t, m, x, y;
    cin >> t;
    while (t--) {
        cin >> m >> x >> y;
        cout << (bruh(m - 1, x, y) ? "crystal" : "empty") << "\n";
    }
}
