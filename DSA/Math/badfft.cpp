#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

/*
simple but slow implementation of FFT, mostly from cp-algorithms.com
*/

typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    if (n == 1) return;
    // resize a to power of two and zero-pad
    if (__builtin_popcount(n) != 1) {
        n = (1 << (32 - __builtin_clz(n)));
        a.resize(n);
    }

    vector<cd> a0(n >> 1), a1(n >> 1);
    for (int i = 0; i < (n >> 1); i++) a0[i] = a[i << 1], a1[i] = a[i << 1 | 1];

    fft(a0, invert); fft(a1, invert);
    double theta = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(theta), sin(theta));
    for (int i = 0; i < (n >> 1); i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + (n >> 1)] = a0[i] - w * a1[i];
        if (invert) a[i] /= 2, a[i + (n >> 1)] /= 2;
        w *= wn;
    }
}