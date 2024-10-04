#include <bits/stdc++.h>
using namespace std;

typedef long long ll;\

// bruh skip all squares? seriously?
/*
1 + 3 + 5 + 7 + ...

x^2 = sum(2i - 1) for i <= x
*/

int t;
ll k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> k;
        ll sq = (ll)sqrt(k), ans = k + sq;
        while (sq * sq < ans) {
            ++sq;
            ++ans;
        }
        cout << ans - 1 << "\n";
    }
    return 0;
}
