#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("deciding_points_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n >> m;
        if (n < m || n == 1) cout << "NO\n";
        else if (n == m || n%2 == 0) cout << "YES\n";
        else if (m >= n - m + 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}