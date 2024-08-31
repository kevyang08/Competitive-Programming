#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int l, r, c = 0;
        cin >> l >> r;
        for (int i = l + (l%2 ? 1 : 2); i < r; i += 4) if (l < i && i < r) ++c;
        cout << c << "\n";
    }
    return 0;
}