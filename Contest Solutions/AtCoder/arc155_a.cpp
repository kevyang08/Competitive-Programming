#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n;
ll k;
string s;
void solve() {
    cin >> n >> k >> s;
    bool ans = true;
    k %= 2 * n;
    if (k > n) k = 2 * n - k;
    for (int i = 0; i < k; i++) if (s[i] != s[i + n - k]) ans = false;
    for (int i = 0; i < n - k; i++) if (s[i] != s[n - k - i - 1]) ans = false;
    for (int i = k; i < n; i++) if (s[i] != s[n - i + k - 1]) ans = false;
    cout << (ans ? "Yes\n" : "No\n");
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