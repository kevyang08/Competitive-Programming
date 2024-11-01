#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        ll ans = (ll)n * (n + 1)/2;
        for (int i = n, j = 0; i > 0; i--) {
            if (s[i - 1] == '1' && i - 1 > j) {
                ++j;
                ans -= i;
            }
            else if (j > 0) --j;
        }
        cout << ans << "\n";
    }
    return 0;
}