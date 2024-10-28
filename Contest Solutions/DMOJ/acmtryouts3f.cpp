#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, r, c, dp[50][50][50], dc[3] = {-1, 0, 1};
string grid[50];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = -0x3f3f3f3f;
        cin >> r >> c;
        for (int i = 0; i < r; i++) cin >> grid[i];
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) for (int k = 0; k < c; k++) dp[i][j][k] = -0x3f3f3f3f;
        for (int i = 1; i < c; i++) {
            if (grid[0][i] == '#') continue;
            for (int j = 0; j < i; j++) {
                if (grid[0][j] == '#') continue;
                dp[0][i][j] = (j + 1 == i);
            }
        }
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (grid[i][j] == '#') continue;
                for (int k = 0; k < j; k++) {
                    if (grid[i][k] == '#') continue;
                    for (int a = 0; a < 3; a++) {
                        if (j + dc[a] < 0 || j + dc[a] >= c || grid[i - 1][j + dc[a]] == '#') continue;
                        for (int b = 0; b < 3; b++) {
                            if (k + dc[b] < 0 || k + dc[b] >= c || dp[i - 1][j + dc[a]][k + dc[b]] == -0x3f3f3f3f || grid[i - 1][k + dc[b]] == '#' || k + dc[b] == j + dc[a]) continue;
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + dc[a]][k + dc[b]] + (k + 1 == j));
                        }
                    }
                }
            }
        }
        for (int i = 1; i < c; i++) for (int j = 0; j < i; j++) ans = max(ans, dp[r - 1][i][j]);
        if (ans == -0x3f3f3f3f) cout << "Detour\n";
        else cout << ans << "\n";
    }
    return 0;
}