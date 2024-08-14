#include <bits/stdc++.h>
using namespace std;

// find two possible squares and find intersections
// can intersect in line if odd n or m, but not both

int t, n, m, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << "? 1 1" << endl;
        cin >> a;
        cout << "? " << n << " " << m << endl;
        cin >> b;
        int r1 = min(a + 1, n), c1 = max(m - b, 1), r2 = max(n - b, 1), c2 = min(a + 1, m);
        if (r1 == r2) {
            cout << "? " << r1 << " " << c1 << endl;
            cin >> a;
            cout << "! " << r1 << " " << c1 + a << endl;
        }
        else if (c1 == c2) {
            cout << "? " << r2 << " " << c2 << endl;
            cin >> a;
            cout << "! " << r2 + a << " " << c2 << endl;
        }
        else {
            cout << "? " << r1 << " " << c1 << endl;
            cin >> a;
            if (a) cout << "! " << r2 << " " << c2 << endl;
            else cout << "! " << r1 << " " << c1 << endl;
        }
    }
    return 0;
}