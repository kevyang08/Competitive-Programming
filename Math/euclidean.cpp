#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
ll modInv(ll a, ll m) {
    ll x, y;
    gcdEx(a, m, &x, &y);
    return (x%m + m)%m;
}
ll modDiv(ll a, ll b, ll m) {
    ll c = modInv(b, m);
    return (c * a)%m;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // Euclidean
    // ll a = 30, b = 20, x, y, gcd = gcdEx(a, b, &x, &y);
    // cout << x << " " << y << " " << gcd;

    // Modular inverse
    // ll a = 3, m = 11;
    // cout << modInv(a, m);

    // Modular division
    ll a = 1, b = 4, m = 5;
    cout << modDiv(a, b, m);
    return 0;
}

/*
Extended Euclidean Algorithm: find x and y such that ax + by = gcd(a, b)

ax + by = gcd(a, b)
gcd(a, b) = gcd(b, a%b)
ax + by = bx1 + (a%b)y1
ax + by = bx1 + (a - [a/b] * b)y1
ax + by = ay1 + b(x1 - [a/b] * y1)
*/

/*
Modular multiplicative inverse: find a^-1 such that (a*a^-1)%m = 1
Note: a and m must be relatively prime, which means gcd(a, m) = 1

Therefore,
(ax + my)%m = 1
ax%m = 1

Lastly, since x = p + qm
a^-1 = x%m
*/

/*
Modular division: to calculate (a%m)/(b%m), find c such that (b * c)%m = a%m

We first find the modular inverse of b, as described previously
We then multiply it by a, giving us the equation
(b*b^-1*a)%m = ((b*b^-1)%m * a%m)%m
             = 1 * a%m
             = a%m
*/