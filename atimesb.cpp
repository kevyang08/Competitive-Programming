#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1) return;
    // resize a to power of two and zero-pad
    if (__builtin_popcount(n) != 1) {
        n = (1 << (32 - __builtin_clz(n)));
        a.resize(n);
    }

    // wtf
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j -= bit;
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) for (cd & x : a) x /= n;
}

string A, B;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> A >> B;
    int n = A.size(), m = B.size(), carry = 0;
    vector<cd> a(n), b(m);
    for (int i = 0; i < n; i++) a[i] = A[n - i - 1] - '0';
    for (int i = 0; i < m; i++) b[i] = B[m - i - 1] - '0';
    n = (1 << (31 - __builtin_clz(n + m) + (__builtin_popcount(n + m) != 1)));
    a.resize(n); b.resize(n);
    fft(a, 0);
    fft(b, 0);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    fft(a, 1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = (int)round(a[i].real()) + carry;
        carry = ans[i]/10;
        ans[i] %= 10;
    }
    while (ans.size() > 1 && !ans.back()) ans.pop_back();
    while (!ans.empty()) {
        cout << ans.back();
        ans.pop_back();
    }
    cout << '\n';
    return 0;
}