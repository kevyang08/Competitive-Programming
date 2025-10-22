#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a, p;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("snake_scales_chapter_1_input.txt", "r", stdin);
    freopen("snake_scales_chapter_1_output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n >> p;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            cin >> a;
            ans = max(ans, abs(a - p));
            p = a;
        }
        cout << ans << "\n";
    }
    return 0;
}