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
        int ans = n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 2, j = 0; i < n; i++) {
            while (v[j] + v[j + 1] <= v[i]) ++j;
            ans = min(ans, j + n - i - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}