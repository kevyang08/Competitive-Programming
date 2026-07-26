#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

ll a, b, k;
int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> a >> b >> k >> t;
    a = abs(a - b);
    ll tmp = a/k;
    ll ans1 = min(tmp + a%k, tmp + (a%k ? 1 : -1) + tmp * k + k - a), ans2 = max(tmp + a%k, tmp + (a%k ? 1 : -1) + tmp * k + k - a);
    ans2 = min(ans2, ans1 + 2);
    if (!a) ans2 = max(ans2, 2LL);
    if (ans2 == ans1) ans2 += 2;
    cout << (t == 1 ? ans1 : ans2) << "\n";
    return 0;
}