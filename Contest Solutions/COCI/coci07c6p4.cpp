#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, k, g, ga[1001], u, v, l, dl[1001], adj[1001][1001], t[1001][1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> a >> b >> k >> g;
    memset(dl, 0x3f3f3f3f, sizeof(dl));
    dl[a] = k;
    for (int i = 0; i < g; i++) cin >> ga[i];
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> l;
        adj[u][v] = adj[v][u] = l;
    }
    memset(t, 0x3f3f3f3f, sizeof(t));
    t[ga[0]][ga[1]] = t[ga[1]][ga[0]] = 0;
    for (int i = 2; i < g; i++) t[ga[i - 1]][ga[i]] = t[ga[i]][ga[i - 1]] = t[ga[i - 2]][ga[i - 1]] + adj[ga[i - 2]][ga[i - 1]];
    pq.push({k, a});
    while (!pq.empty()) {
        pair c = pq.top(); pq.pop();
        for (int i = 1; i <= n; i++) {
            if (adj[c.second][i] == 0) continue;
            int temp = c.first + adj[c.second][i] + (t[c.second][i] == 0x3f3f3f3f || t[c.second][i] > c.first || t[c.second][i] + adj[c.second][i] <= c.first ? 0 : t[c.second][i] + adj[c.second][i] - c.first);
            if (temp < dl[i]) {
                pq.push({temp, i});
                dl[i] = temp;
            }
        }
    }
    cout << dl[b] - k << "\n";
    return 0;
}
