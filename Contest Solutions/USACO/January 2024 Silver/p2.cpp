#include <bits/stdc++.h>
using namespace std;

int n, a, b, bruh = 0, ans = 0, p[200001], arr[200001];
vector<int> adj[200001];
int dfs(int i, int p) {
    if (adj[i].size() == 1 && adj[i][0] == p) {
        if (arr[i]) {
            ans++;
            return 0;
        }
        return 1;
    }
    int thing = 0;
    for (int j : adj[i]) if (j != p) thing += dfs(j, i);
    if (arr[i]) {
        ans += min(thing, arr[i]);
        thing = max(0, thing - arr[i]);
    }
    return thing;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 2; i <= n; i++) if (adj[i].size() == 1) bruh++;
    for (int i = 1; i <= bruh; i++) arr[p[i]]++;
    dfs(1, 0);
    cout << ans << "\n";
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
