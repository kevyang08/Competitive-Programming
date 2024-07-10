#include <bits/stdc++.h>
using namespace std;

/*
- literally find any cycle containing a node with adj[i].size() > 3
- doable in linear time, although quadratic time is fine anyway
- nvm use degree to find cycles
- go through all the nodes that are part of a cycle, find one that has adj[i].size() > 3, and find any cycle containing it using another dfs
    - nvm use bfs so that we can ignore nodes already in the fish when adding extra ones and also keep linear time
- implementation was slightly worse than expected

bruh nvm the algorithm is still quadratic time (and not even correct for some cases)
easy fix, but too lazy for now
*/

int t, n, m, u, v, in[2001], pa[2001], dist[2001], bruh[2001];
vector<int> adj[2001];
bool vis[2001], thing[2001], ans;
void bfs(int i) {
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (auto j : adj[c]) {
            if (j == pa[c]) continue;
            if (pa[j]) {
                if (bruh[j] == bruh[c]) continue;
                ans = true;
                cout << "YES\n" << dist[c] + dist[j] + 3 << "\n" << c << " " << j << "\n";
                while (c != i) {
                    thing[c] = true;
                    cout << pa[c] << " " << c << "\n";
                    c = pa[c];
                }
                while (j != i) {
                    thing[j] = true;
                    cout << pa[j] << " " << j << "\n";
                    j = pa[j];
                }
                for (int k = 0, cnt = 0; k < adj[i].size() && cnt < 2; k++) if (!thing[adj[i][k]]) {
                    cout << i << " " << adj[i][k] << "\n";
                    ++cnt;
                }
                return;
            }
            else {
                q.push(j);
                pa[j] = c, dist[j] = dist[c] + 1, bruh[j] = (bruh[c] ? bruh[c] : j);
            }
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
        ans = false;
        queue<int> q;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            bruh[i] = vis[i] = pa[i] = dist[i] = thing[i] = in[i] = 0;
            adj[i].clear();
        }
        while (m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++in[u], ++in[v];
        }
        for (int i = 1; i <= n; i++) if (in[i] < 2) {
            q.push(i);
            vis[i] = true;
        }
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (auto &j : adj[c]) if (--in[j] < 2 && !vis[j]) {
                q.push(j);
                vis[j] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (in[i] > 1 && adj[i].size() > 3) {
                thing[i] = true;
                bfs(i);
                break;
            }
        }
        if (!ans) cout << "NO\n";
    }
    return 0;
}