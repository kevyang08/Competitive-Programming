#include <bits/stdc++.h>
using namespace std;

int t, s, d, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("cheeseburger_corollary_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        cin >> s >> d >> k;
        cout << "Case #" << bruh << ": " << (s * 2 + d * 2 > k && s + d * 2 >= k ? "YES" : "NO") << "\n";
    }
    return 0;
}
