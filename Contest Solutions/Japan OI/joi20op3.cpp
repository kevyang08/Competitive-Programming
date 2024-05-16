#include <bits/stdc++.h>
using namespace std;

// the code is way worse than before but at least its actually correct now (hopefully)

int n, a, b, dp[200001], ans = 0;
string s;
vector<int> adj[200001];
void dfs1(int i, int p) {
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs1(j, i);
        // if child has a power generator, we can always take at least 1
        if (s[j - 1] == '1') dp[i] += max(dp[j] - 1, 1);
        else dp[i] += dp[j];
    }
}
void dfs2(int i, int p, int v) {
    // propagating down
    dp[i] += v;
    int cnt = 0; // count how many branches from this node contain at least one power generator
    if (v) cnt++;
    for (int j : adj[i]) {
        if (j == p) continue;
        if (dp[j] || s[j - 1] == '1') cnt++;
    }
    for (int j : adj[i]) {
        if (j == p) continue;
        // calculating the additional amount added from j to dp[i]
        int thing = s[j - 1] != '1' ? 0 : dp[j] > 1 ? 1 : dp[j] ? 0 : -1;
        // this generator would be broken
        if (s[i - 1] == '1' && (cnt > 1 || cnt == 1 && !dp[j] && s[j - 1] != '1')) dfs2(j, i, max(1, dp[i] - 1 - dp[j] + thing));
        else dfs2(j, i, dp[i] + (s[i - 1] == '1') - dp[j] + thing);
    }
    if (s[i - 1] == '1') {
        if (cnt < 2) dp[i]++;
        else dp[i] = max(2, dp[i] - 1); // always at least 2 unless there is only one power generator in the graph
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}
