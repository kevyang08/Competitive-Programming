#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x[2005], y[2005], z[2005], q[2005][2005], MOD = 1000000007, MM = MOD * MOD;
vector<ll> Q;
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
    Q.push_back(-1);
    Q.push_back(1);
    for (int i = 1; i <= n + 1; i++) {
        x[i] = i;
        cout << "? " << i << endl;
        cin >> y[i];
        if (i == 1) continue;
        ll curr = 0, prev = 0;
        for (int j = 0; j < Q.size(); j++) {
            prev = Q[j];
            Q[j] = (Q[j] * -i + curr)%MOD;
            curr = prev;
        }
        Q.push_back(1);
    }
    for (int k = 1; k <= n + 1; k++) {
        ll xpow = 1;
        q[k][1] = modDiv(-Q[0], x[k]);
        z[k] = (z[k] + q[k][1] * xpow)%MOD;
        for (int i = 2; i <= n + 1; i++) {
            xpow = (xpow * x[k])%MOD;
            q[k][i] = modDiv(-Q[i - 1] + q[k][i - 1], x[k]);
            z[k] = (z[k] + q[k][i] * xpow)%MOD;
        }
    }
    cout << "!";
    for (int i = n + 1; i >= 1; i--) {
        ll num = 0, den = 1, bruh = 0;
        for (int k = 1; k <= n + 1; k++) {
            bruh = (z[k] * (den/__gcd(z[k], den)));
            num = ((num * (bruh/den)%MOD)%MOD + ((y[k] * q[k][i])%MOD * (bruh/z[k])%MOD)%MOD + MM)%MOD;
            den = bruh%MOD;
        }
        cout << " " << modDiv(num, den);
    }
    cout << endl;
    return 0;
}

/*
3
4
29
106
265
*/
