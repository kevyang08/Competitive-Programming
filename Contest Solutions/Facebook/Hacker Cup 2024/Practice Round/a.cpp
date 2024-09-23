#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll n, s, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("walk_the_line_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        ll mn = 0x3f3f3f3f;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mn = min(mn, s);
        }
        cout << (mn * 2 * max(n - 1, 1LL) - mn <= k ? "YES\n" : "NO\n");
    }
    return 0;
}