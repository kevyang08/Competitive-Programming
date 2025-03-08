#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*

*/

const int M = 1e9 + 7;

int n, u, v;
ll dp[2][300001], ans = 0;
string s;
vector<int> adj[300001];
void dfs(int i, int p) {
    vector<ll> tot(2);
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        ans = (ans + (tot[0] + dp[0][i]) * dp[0][j] + (tot[1] + dp[1][i]) * dp[1][j])%M;
        if (s[i - 1] == 'R') ans = (ans + dp[0][j])%M;
        else ans = (ans + dp[1][j])%M;
        dp[0][i] = (dp[0][i] + dp[0][j] * (tot[0] + dp[0][i]))%M;
        dp[1][i] = (dp[1][i] + dp[1][j] * (tot[1] + dp[1][i]))%M;
        tot[0] = (dp[0][j] + tot[0])%M;
        tot[1] = (dp[1][j] + tot[1])%M;
    }
    dp[0][i] = (dp[0][i] + tot[0])%M;
    dp[1][i] = (dp[1][i] + tot[1])%M;
    if (s[i - 1] == 'R') ++dp[0][i];
    else ++dp[1][i];
    ans = (ans + 1)%M;

    // cout << i << " " << dp[0][i] << " " << dp[1][i] << " debug\n"; // debug
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}