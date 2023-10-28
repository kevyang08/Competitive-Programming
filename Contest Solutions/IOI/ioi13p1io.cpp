#include <bits/stdc++.h>
using namespace std;

int n, m, l, a, b, t, dp[100000][2], bruh = 0;
vector<pair<int, int>> adj[100000];
bool vis[100000];
vector<int> v;
void dfs1(int i) {
    vis[i] = true;
    for (auto p : adj[i]) {
        if (vis[p.first]) continue;
        dfs1(p.first);
        if (p.second + dp[p.first][0] > dp[i][0]) {
            dp[i][1] = dp[i][0];
            dp[i][0] = p.second + dp[p.first][0];
        }
        else if (p.second + dp[p.first][0] > dp[i][1]) dp[i][1] = p.second + dp[p.first][0];
    }
}
int dfs2(int i, int pa, int mx) {
    bool thing = mx >= dp[i][0];
    int ans = max(mx, dp[i][0]);
    bruh = max(bruh, ans);
    for (auto p : adj[i]) {
        if (p.first == pa) continue;
        if (thing || p.second + dp[p.first][0] != dp[i][0]) ans = min(ans, dfs2(p.first, i, p.second + max(mx, dp[i][0])));
        else {
            ans = min(ans, dfs2(p.first, i, p.second + max(mx, dp[i][1])));
            thing = true;
        }
    }
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> l;
    while (m--) {
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs1(i);
        v.push_back(dfs2(i, i, 0LL));
    }
    sort(v.begin(), v.end());
    cout << max(v.size() == 1 ? v[0] : v.size() == 2 ? v[0] + v[1] + l : max(v[v.size() - 3] + v[v.size() - 2] + 2 * l, v[v.size() - 1] + v[v.size() - 2] + l), bruh) << "\n";
    return 0;
}
