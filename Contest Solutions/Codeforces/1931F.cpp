#include <bits/stdc++.h>
using namespace std;
 
int t, n, k, a[200001];
vector<int> adj[200001];
bool vis[200001], cur[200001];
bool dfs(int i) {
    vis[i] = cur[i] = true;
    bool thing = true;
    for (int j : adj[i]) {
        if (cur[j]) thing = false;
        if (!vis[j]) thing &= dfs(j);
    }
    cur[i] = false;
    return thing;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            vis[i] = false;
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[j];
                if (j > 2) adj[a[j]].push_back(a[j - 1]);
            }
        }
        bool ans = true;
        for (int i = 1; i <= n; i++) if (!vis[i]) ans &= dfs(i);
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}
 
/*
1
10 2
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
 
 
1
3 3
1 3 2
2 1 3
3 2 1
 
*/
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
