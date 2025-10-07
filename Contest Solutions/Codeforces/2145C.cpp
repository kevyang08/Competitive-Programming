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
string s;
void solve() {
    cin >> n >> s;
    int diff = 0, cur = 0, ans = n;
    for (int i = 0; i < n; i++) diff += (s[i] == 'a' ? 1 : -1);
    map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        cur += (s[i] == 'a' ? 1 : -1);
        mp[cur] = i;
        if (mp.find(cur - diff) != mp.end()) ans = min(ans, i - mp[cur - diff]);
    }
    cout << (ans == n ? -1 : ans) << "\n";
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