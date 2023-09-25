#include <bits/stdc++.h>
using namespace std;

int t, r, c, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("dim_sum_delivery_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        cin >> r >> c >> a >> b;
        cout << "Case #" << bruh << ": " << (r > c ? "YES" : "NO") << "\n";
    }
    return 0;
}
