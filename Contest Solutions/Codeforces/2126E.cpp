#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, p[100001], s[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    if (n == 1) {
        cout << (p[1] == s[1] ? "YES\n" : "NO\n");
        return;
    }
    if (n == 2) {
        cout << (__gcd(p[1], s[2]) == p[2] && p[2] == s[1] ? "YES\n" : "NO\n");
        return;
    }
    bool ans = (p[n] == s[1] && __gcd(p[1], s[n])%s[1] == 0);
    for (int i = 1; i < n; i++) {
        ans &= s[i + 1]%s[i] == 0;
        ans &= p[i]%p[i + 1] == 0;
        ans &= __gcd(p[i], s[i + 1]) == p[n];
    }
    cout << (ans ? "YES\n" : "NO\n");
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}