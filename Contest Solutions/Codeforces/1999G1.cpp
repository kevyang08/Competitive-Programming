#include <bits/stdc++.h>
using namespace std;

int t, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int l = 2, r = 999;
        while (l < r) {
            int m1 = l + (r - l)/3, m2 = r - (r - l + 1)/3;
            cout << "? " << m1 << " " << m2 << endl;
            cin >> a;
            if (a == (m1 + 1) * (m2 + 1)) r = m1;
            else if (a == m1 * (m2 + 1)) l = m1 + 1, r = m2;
            else l = m2 + 1;
        }
        cout << "! " << r << endl;
    }
    return 0;
}