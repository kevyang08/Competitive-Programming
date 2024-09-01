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
        long long l, r;
        cin >> l >> r;
        long long ans = (long long)sqrt((r - l) * 2) + 1;
        if (l + ans * (ans - 1)/2 > r) --ans;
        cout << ans << "\n";
    }
    return 0;
}