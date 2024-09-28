#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, dr[4] = {-1, -1, -1, -2}, dc[4] = {-1, 0, 1, 0};
ll ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= m; j++) {
            if (i > 2 && j > 1 && j < m) {
                int mn = i/2 + i%2, thing = 1;
                for (int k = 0; k < 4; k++) {
                    if (s[i + dr[k]][j + dc[k] - 1] != s[i][j - 1]) {
                        mn = 1;
                        thing = 0;
                        break;
                    }
                    mn = min(mn, dp[i + dr[k]][j + dc[k]]);
                }
                dp[i][j] = mn + thing;
            }
            ans += dp[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}