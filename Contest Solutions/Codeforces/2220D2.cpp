#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, res;
void solve() {
    cin >> n;
    n = 2 * n + 1;
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        int l = 1, r = n;
        if (!v.empty()) l = v.back() + 1;
        while (l < r) {
            int m = (l + r + 1)/2;
            cout << "? " << v.size() + n - m + 1;
            for (int j : v) cout << " " << j;
            for (int j = m; j <= n; j++) cout << " " << j;
            cout << endl;
            cin >> res;
            if (res%2 != (v.size() + n - m + 1)%2) l = m;
            else r = m - 1;
        }
        v.push_back(l);
    }
    cout << "! " << v[0] << " " << v[1] << " " << v[2] << endl;
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