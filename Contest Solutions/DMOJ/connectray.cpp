#include <bits/stdc++.h>
using namespace std;

int n, m, q, a, b;
vector<int> adj[400001];
bool vis[400001];
char op;
void dfs(int i, int k = 0) {
    vis[i] = true;
    if (k) dfs(k);
    else for (int j : adj[i]) if (!vis[j]) dfs(j);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    while (q--) {
        cin >> op >> a;
        if (op == '?') cout << (vis[a] ? "YES\n" : "NO\n");
        else {
            cin >> b;
            adj[a].push_back(b);
            if (vis[a] && !vis[b]) dfs(a, b);
        }
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
