#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int t, n, a;
void solve() {
    cin >> n;
    vector<int> cnt(n + 1);
    int mx = 0, prv = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        int cur = 0;
        for (int j = 1; j * j <= a; j++) {
            if (a%j) continue;
            ++cnt[j];
            if (cnt[j] == i) ++cur;
            else mx = max(mx, cnt[j]);
            if (a/j != j) {
                ++cnt[a/j];
                if (cnt[a/j] == i) ++cur;
                else mx = max(mx, cnt[a/j]);
            }
        }
        if (cur < prv) mx = i - 1;
        cout << mx << ' ';
        prv = cur;
    }
    cout << '\n';
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