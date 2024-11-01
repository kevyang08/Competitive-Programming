#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a;
            cnt += a;
        }
        cout << cnt%2 << " " << (cnt <= n ? cnt : 2 * n - cnt) << "\n";
    }
    return 0;
}