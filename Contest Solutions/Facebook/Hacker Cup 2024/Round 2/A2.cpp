#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
- how to efficiently check divisibility?
- shit i fumbled shouldve solved this instaed of b
- 2 ^ 16 possilities

Post contest: The last claim is not correct. The actual number is about 80 million according to official sources.
*/

int t, m;
ll a, b;
ll solve(ll n, int l, int r, int d, int mid) {
    if (r == d && n%10 >= mid || n > b) return 0;
    if (l == 0 && r == d) n = n * 10 + mid;
    if (l == 0 && r == 0) {
        // cout << n << " bruh\n";
        return (a <= n && n <= b && n%m == 0 ? 1 : 0);
    }
    ll res = 0;
    if (l) {
        if (l == d) {
            for (int i = 1; i + n%10 < 10; i++) res += solve(n * 10 + n%10 + i, l - 1, r, d, mid);
        }
        else {
            for (int i = 0; i + n%10 < 10; i++) res += solve(n * 10 + n%10 + i, l - 1, r, d, mid);
        }
    }
    else {
        if (r == d) {
            for (int i = 1; i < n%10; i++) res += solve(n * 10 + n%10 - i, l, r - 1, d, mid);
        }
        else {
            for (int i = 0; i < n%10; i++) res += solve(n * 10 + n%10 - i, l, r - 1, d, mid);
        }
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("cottontail_climb_part_2_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> a >> b >> m;
        ll ans = 0;
        for (int i = 1; i < 10; i++) for (int j = 0; j < 9; j++) ans += solve(0, j, j, j, i);
        cout << ans << "\n";
    }
    return 0;
}