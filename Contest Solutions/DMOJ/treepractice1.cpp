#include <bits/stdc++.h>
using namespace std;

int n, u, v, w, d = 0, r = 0x3f3f3f3f, mx[500001][2], midx[500001];
vector<pair<int, int>> adj[500001];
bool vis[500001];
void dfs(int i) {
    vis[i] = true;
    int temp = 0;
    for (pair p : adj[i]) {
        if (vis[p.first]) continue;
        dfs(p.first);
        int res = mx[p.first][0] + p.second;
        if (res > mx[i][0]) {
            temp = res;
            res = mx[i][0];
            mx[i][0] = temp;
            midx[i] = p.first;
        }
        if (res > mx[i][1]) mx[i][1] = res;
    }
    d = max(d, mx[i][0] + mx[i][1]);
}
void dfs(int i, int bruh) {
    vis[i] = false;
    for (pair p : adj[i]) {
        if (!vis[p.first]) continue;
        dfs(p.first, max(bruh, (p.first == midx[i] ? mx[i][1] : mx[i][0])) + p.second);
    }
    r = min(r, max(bruh, mx[i][0]));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    dfs(1, 0);
    cout << d << "\n" << r << "\n";
}
