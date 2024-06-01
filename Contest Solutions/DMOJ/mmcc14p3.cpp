#include <bits/stdc++.h>
using namespace std;

int n, s, u, v, dp[5001];
vector<int> adj[5001];
int dfs(int i, int p, int m) {
    dp[i] = 0;
    int res = (adj[i].size() > 1 ? 0 : m + 1), mn = 0x3f3f3f3f;
    for (int j : adj[i]) {
        if (j == p) continue;
        int temp = dfs(j, i, m) + 1;
        res = max(res, temp);
        if (dp[j]) mn = min(mn, temp);
        dp[i] += dp[j];
    }
    if (mn + res - 1 <= 2 * m) return mn;
    else if (res > 2 * m) {
        dp[i]++;
        return 0;
    }
    if (i == 1 && res > m) dp[i]++;
    return res;
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
    int l = 0, r = n/2;
    while (l < r) {
        int m = (l + r)/2;
        dfs(1, 0, m);
        if (dp[1] <= s) r = m;
        else l = m + 1;
    }
    cout << r << "\n";
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
