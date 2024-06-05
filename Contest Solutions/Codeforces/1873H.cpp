#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, u, v, in[200001], dist[2][200001];
bool safe[200001];
vector<int> adj[200001];
void bfs(int i, int thing) {
    queue<int> q;
    dist[thing][i] = 0;
    q.push(i);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int j : adj[c]) {
            if (dist[thing][c] + 1 < dist[thing][j]) {
                dist[thing][j] = dist[thing][c] + 1;
                q.push(j);
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
        queue<int> q;
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++) {
            safe[i] = true;
            dist[0][i] = dist[1][i] = 0x3f3f3f3f;
            adj[i].clear();
            in[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            in[u]++; in[v]++;
        }
        for (int i = 1; i <= n; i++) if (in[i] == 1) q.push(i);
        while (!q.empty()) {
            int c = q.front(); q.pop();
            safe[c] = false;
            for (int i : adj[c]) {
                in[i]--;
                if (in[i] == 1) q.push(i);
            }
        }
        bfs(a, 0);
        bfs(b, 1);
        bool bruh = false;
        for (int i = 1; i <= n; i++) if (safe[i] && dist[0][i] > dist[1][i]) bruh = true;
        cout << (bruh ? "YES\n" : "NO\n");
    }
    return 0;
}
