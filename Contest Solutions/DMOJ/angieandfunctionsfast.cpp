#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x[2005][2005], y[2005], p[2005][2005], f[2005], MOD = 1000000007, MM = MOD * MOD;
ll gcdEx(ll a, ll b, ll *cx, ll *cy) {
    if (a%b == 0) {
        *cx = 0;
        *cy = 1;
        return b;
    }
    ll x1, y1, gcd = gcdEx(b, a%b, &x1, &y1);
    *cx = y1;
    *cy = x1 - (a/b) * y1;
    return gcd;
}
ll modInv(ll a) {
    ll cx, cy;
    gcdEx(a, MOD, &cx, &cy);
    return (cx%MOD + MOD)%MOD;
}
ll modDiv(ll a, ll b) {
    if (a < 0) a += MOD;
    ll c = modInv(b);
    return (c * a)%MOD;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    f[0] = 1;
    for (int i = 0; i <= n; i++) {
        x[i][0] = 1;
        for (int j = 1; j <= n; j++) x[i][j] = (x[i][j - 1] * i)%MOD;
        cout << "? " << i << endl;
        cin >> y[i];
        if (i > 0) f[i] = (f[i - 1] * i)%MOD;
    }
    p[1][1] = 1;
    for (int i = 2; i <= n + 1; i++) for (int j = 1; j <= n + 1; j++) p[i][j] = (p[i - 1][j] - p[i - 1][j - 1])%MOD;
    cout << "!";
    for (int k = n; k >= 0; k--) {
        ll a, kd = 0;
        for (int j = 0; j <= k; j++) kd = (kd + (p[k + 1][j + 1] * y[n - j])%MOD + MM)%MOD;
        a = modDiv(kd, f[k]);
        cout << " " << a;
        for (int j = 0; j <= n; j++) y[j] = (y[j] - (a * x[j][k])%MOD + MM)%MOD;
    }
    cout << endl;
    return 0;
}
