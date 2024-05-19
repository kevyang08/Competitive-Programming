#include <bits/stdc++.h>
using namespace std;

// time: ~45 mins
// was a bit stupid, should've read more carefully

/*
https://dmoj.ca/problem/aac7p2

- we can always choose k = children(1) + 1
- can't always choose k = 2 since children of 1 cannot be ancestors of each other
*/

int n, u, v;
vector<int> adj[200001], ans[200001], tree[200001];
void dfs(int i, int p, int pp, int t, int d) {
    tree[t ^ (t * d)].push_back(i);
    if (pp) ans[pp].push_back(i);
    for (int j : adj[i]) {
        if (j == p) continue;
        if (i == 1) dfs(j, i, p, j, d);
        else dfs(j, i, p, t, d ^ 1);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 1) {
        cout << "1\n1\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0, 0, 0);
    cout << adj[1].size() + 1 << "\n";
    for (auto &a : tree) {
        if (a.empty()) continue;
        cout << a.size() << "\n";
        for (int i : a) for (int j : ans[i]) cout << i << " " << j << "\n";
    }
    return 0;
}
