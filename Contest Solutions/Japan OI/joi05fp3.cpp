#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n;
vector<vector<vector<int>>> dp;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            for (int k = 0; k < dp[j].size(); k++) {
                if (i - j < dp[j][k].back()) break;
                dp[i].push_back(dp[j][k]);
                dp[i].back().push_back(i - j);
            }
        }
        dp[i].push_back(vector<int>());
        dp[i].back().push_back(i);
    }
    for (int i = dp[n].size() - 1; i >= 0; i--) {
        for (int j = dp[n][i].size() - 1; j >= 0; j--) cout << dp[n][i][j] << (j ? " " : "\n");
    }
    for (int i = 1; i <= n; i++) cout << dp[i].size() << " ";
    return 0;
}