#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long ans = 0;
        for (long long i = 1; i <= min(n, m); i++) ans += (n + i)/(i * i);
        cout << ans - 1 << "\n";
    }
    return 0;
}
