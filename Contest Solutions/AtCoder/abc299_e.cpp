#include <bits/stdc++.h>
using namespace std;
 
int n, m, u, v, k, p, d, dist[2001][2001];
vector<int> adj[2001], bruh[2001];
bool thing = true, b[2001], vis[2001];
map<int, int> mp;
void bfs(int i) {
    dist[i][i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int j : adj[c]) {
            if (dist[i][c] + 1 >= dist[i][j]) continue;
            dist[i][j] = dist[i][c] + 1;
            q.push(j);
            if (mp.find(i) != mp.end() && mp[i] == dist[i][j]) bruh[i].push_back(j);
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;
    if (k == 0) b[1] = true;
    for (int i = 1; i <= k; i++) {
        cin >> p >> d;
        mp.emplace(p, d);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    for (pair p : mp) {
        if (p.second == 0) bruh[p.first].push_back(p.first);
        int temp = 0;
        for (int i : bruh[p.first]) {
            if (vis[i]) {
                if (b[i]) temp++;
                continue;
            }
            bool temptemp = true;
            b[i] = true;
            for (int j = 1; j <= n; j++) {
                if (j == p.first || mp.find(j) == mp.end()) continue;
                else if (dist[j][i] < mp[j]) {
                    temptemp = false;
                    b[i] = false;
                }
            }
            if (temptemp) temp++;
            vis[i] = true;
        }
        if (temp == 0) thing = false;
    }
    if (thing) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) cout << (b[i] ? 1 : 0);
        cout << "\n";
    }
    else cout << "No\n";
    return 0;
}
