#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, a;
void solve() {
    cin >> n >> k;
    int l = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a) l = 0;
        else ++l;
        if (l >= k) {
            ++ans;
            l = -1;
        }
    }
    cout << ans << "\n";
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