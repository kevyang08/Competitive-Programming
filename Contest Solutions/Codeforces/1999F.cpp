#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1e9 + 7;

int t, n, k, a, c[2];
ll f[200001];
ll gcdEx(ll a, ll b, ll *x, ll *y) {
    if (a%b == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1, gcd = gcdEx(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    return gcd;
}
ll modInv(ll a) {
    ll x, y;
    gcdEx(a, M, &x, &y);
    return (x%M + M)%M;
}
ll modDiv(ll a, ll b) {
    ll c = modInv(b);
    return (c * (a%M))%M;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    f[0] = 1;
    for (int i = 1; i <= 200000; i++) f[i] = (f[i - 1] * i)%M;
    cin >> t;
    while (t--) {
        c[0] = c[1] = 0;
        cin >> n >> k;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            ++c[a];
        }
        for (int i = 0; i <= k/2; i++) {
            if (i > c[0] || k - i > c[1]) continue;
            ans = (ans + (modDiv(f[c[0]], (f[i] * f[c[0] - i])%M) * modDiv(f[c[1]], (f[k - i] * f[c[1] - k + i])%M))%M)%M;
        }
        cout << ans << "\n";
    }
    return 0;
}