#include <bits/stdc++.h>
using namespace std;

int t, n, u, v, sz[200001];
vector<pair<int, int>> adj[200001];
vector<int> ans;
bool thing;
void dfs(int i, int p) {
    sz[i] = 1;
    for (auto &[j, e] : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        if (sz[j] == 3) ans.push_back(e);
        else if (sz[j] > 3) thing = false;
        else sz[i] += sz[j];
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        ans.clear();
        thing = true;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        dfs(1, 0);
        if (thing && sz[1] == 3) {
            cout << ans.size() << "\n";
            for (auto &i : ans) cout << i << " ";
            cout << "\n";
        }
        else cout << "-1\n";
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