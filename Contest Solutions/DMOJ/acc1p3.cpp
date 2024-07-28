#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long M = 998244353;

int n;
ll t, a[100001], b[100001];

// bruh
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
    return (c * (a%m))%m;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> t;
    ll ans = 0, l = 0, r = 1e18;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    while (l <= r) {
        ll m = (l + r)/2, c = 0, res = 0, bruh = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == m) ++bruh;
            if (a[i] <= m) continue;
            ll temp = (a[i] - m)/b[i] + 1;
            if (a[i] - b[i] * (temp - 1) == m) --temp, ++bruh;
            res = (res + ((a[i]%M) * (temp%M) - modDiv(((temp - 1)%M) * (temp%M), 2, M) * (b[i]%M) + M * M)%M + M * M)%M;
            c += temp;
            if (c > 2 * t) break;
        }
        if (c <= t) {
            ans = (res + (min(t - c, bruh)%M * (m%M))%M)%M;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans << "\n";
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/