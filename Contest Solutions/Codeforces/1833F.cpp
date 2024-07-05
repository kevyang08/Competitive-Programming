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
ll f[200001];
int t, n, m;
vector<int> a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    f[0] = 1;
    for (int i = 1; i <= 200000; i++) f[i] = (f[i - 1] * i)%M;
    cin >> t;
    while (t--) {
        map<int, int> c;
        ll ans = 0, thing = 1;
        cin >> n >> m;
        a.resize(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        for (int i = 0, j = 0; i < n; i++) {
            c[a[i]]++;
            if (c[a[i]] > 1) thing = (modDiv(thing, c[a[i]] - 1, M) * c[a[i]])%M;
            if (i < n - 1 && a[i] == a[i + 1]) continue;
            while (j < i && a[i] - a[j] >= m) {
                --c[a[j]];
                if (!c[a[j]]) c.erase(a[j]);
                else thing = (modDiv(thing, c[a[j]] + 1, M) * c[a[j]])%M;
                ++j;
            }
            if (c.size() < m) continue;
            ans = (ans + modDiv(f[c.size()], (f[c.size() - m] * f[m])%M, M) * thing)%M;
        }
        cout << ans << "\n";
    }
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