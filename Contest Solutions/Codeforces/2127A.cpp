#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a[101];
void solve() {
    cin >> n;
    bool ans = true;
    int thing = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) ans = false;
        if (a[i] != -1) {
            if (thing != -1 && thing != a[i]) ans = false;
            thing = a[i];
        }
        if (i < 3) continue;
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