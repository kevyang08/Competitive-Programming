#include <bits/stdc++.h>
using namespace std;

// dp[i][j] will hold the xor'd count of the jth bit of all the non-repeated paths that end at node i
int n, v[100001], a, b, dp[100001][32], cnt[100001], dp2[100001][32], cnt2[100001];
long long ans = 0;
vector<int> adj[100001];
void dfs1(int i, int p) {
    cnt[i] = 1;
    for (int j = 0; j < 32; j++) if (v[i] & (1 << j)) dp[i][j] = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs1(j, i);
        for (int k = 0; k < 32; k++) dp[i][k] += (v[i] & (1 << k)) ? cnt[j] - dp[j][k] : dp[j][k];
        cnt[i] += cnt[j];
    }
    for (int j = 0; j < 32; j++) dp2[i][j] = dp[i][j] - ((v[i] & (1 << j)) >> j);
    cnt2[i] = cnt[i];
}
void dfs2(int i, int p) { // add arrays to push down, count
    for (int j = 0; j < 32; j++) dp2[i][j] += (v[i] & (1 << j)) ? cnt2[p] - dp2[p][j] : dp2[p][j];
    cnt2[i] += cnt2[p] - 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        cnt2[i] -= cnt[j];
        for (int k = 0; k < 32; k++) dp2[i][k] -= (v[i] & (1 << k)) ? cnt[j] - dp[j][k] : dp[j][k];
        dfs2(j, i);
    }
    for (int j = 0; j < 32; j++) dp[i][j] += dp2[i][j];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) for (int j = 0; j < 32; j++) ans += (long long)dp[i][j] * (1 << j);
    cout << ans << "\n";
    return 0;
}
