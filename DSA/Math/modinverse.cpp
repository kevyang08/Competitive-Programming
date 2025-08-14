#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
simpler mod inverse
*/

const int M = 1e9 + 7;

ll bpow(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) res = (res * n)%M;
        n = (n * n)%M;
        p >>= 1;
    }
    return res;
}
ll modinv(ll a) {
    return bpow(a, M - 2);
}