#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1e9 + 7;

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
int t, n, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        ll s = 0, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s = (s + a[i])%M;
        }
        for (int i = 0; i < n; i++) {
            s = (s - a[i] + M)%M;
            ans = (ans + s * a[i])%M;
        }
        cout << (ans * modInv((ll)n * (n - 1)/2, M))%M << "\n";
    }
    return 0;
}