#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 1e9 + 7;

int t, n, a;
void solve() {
    cin >> n;
    int cur = 0, ans = 0, cz = 1;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a;
        int tmp = 0;
        if (cz) {
            tmp = cz;
            cz = 0;
        }
        cur ^= a;
        if (mp.find(cur) != mp.end()) {
            cz = mp[cur];
            mp[cur ^ a] = (mp[cur ^ a] + mp[cur] * 2LL)%M;
            mp.erase(cur);
        }
        if (tmp) mp[cur ^ a] = (mp[cur ^ a] + tmp * 3LL)%M;
    }
    for (auto &[k, v] : mp) ans = (ans + v)%M;
    cout << (ans + cz)%M << "\n";
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