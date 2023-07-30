#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll m, a[2000], c[2000], MOD = 1000000007;
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
    gcdEx(a, MOD, &x, &y);
    return (x%MOD + MOD)%MOD;
}
ll modDiv(ll a, ll b) {
    ll c = modInv(b);
    return (c * a)%MOD;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    c[0] = 1;
    for (int i = 1; i < n; i++) c[i] = modDiv((c[i - 1] * (m + i - 1)%MOD)%MOD, i);
    for (int i = n - 1; i > 0; i--) for (int j = i - 1; j >= 0; j--) a[i] = (a[i] + (c[i - j] * a[j])%MOD)%MOD;
    for (int i = 0; i < n; i++) cout << (i == 0 ? "" : " ") << a[i];
    return 0;
}
