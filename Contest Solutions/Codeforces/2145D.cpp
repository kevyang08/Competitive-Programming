#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, k;
void solve() {
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(n * (n - 1)/2 + 1));
    vector<vector<int>> thing(n + 1, vector<int>(n * (n - 1)/2 + 1));
    dp[n][0] = 0x3f3f3f3f;
    for (int i = n - 1; i > 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            int tmp = i * (j - i);
            for (int kk = tmp; kk <= n * (n - 1)/2; kk++) {
                if (dp[j][kk - tmp]) {
                    dp[i][kk] = j;
                    thing[i][kk] = kk - tmp;
                }
            }
        }
    }
    int j = 0;
    for (int i = 1; i <= n; i++) if (dp[i][k]) j = i;
    if (!j) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i < j) cout << i << ' ';
        else {
            while (dp[j][k] == j + 1) {
                ++j;
                k = thing[j - 1][k];
            }
            for (int l = min(n, j + 1); l >= i; l--) cout << l << ' ';
            i = min(n, j + 1);
            j = dp[j][k];
            k = thing[i - 1][k];
        }
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