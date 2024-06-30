#include <bits/stdc++.h>
using namespace std;

/*
- nvm last solution was basically tarjan (def did not steal the tin idea)
- just gonna use tarjan properly this time
*/

int t, n, m, u, v, tin[100001], lo[100001], cnt;
vector<int> adj[100001];
long long ans = 0, sz[100001];
void dfs(int i, int p) {
    lo[i] = tin[i] = ++cnt;
    sz[i] = 1;
    for (auto j : adj[i]) {
        if (j == p) continue;
        if (tin[j]) lo[i] = min(lo[i], lo[j]);
        else {
            dfs(j, i);
            lo[i] = min(lo[i], lo[j]);
            if (tin[i] < lo[j]) {
                long long x = n - sz[j];
                ans = min(ans, x * (x - 1)/2 + sz[j] * (sz[j] - 1)/2);
            }
            sz[i] += sz[j];
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ans = (long long)n * (n - 1)/2;
        cnt = 0;
        tin[0] = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            tin[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        cout << ans << "\n";
    }
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

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/