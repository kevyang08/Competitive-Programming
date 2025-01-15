#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
Implementation of the Edmonds-Karp algorithm that finds the max flow of a network from a source node s 
to a sink node t in O(VE^2), where E is the number of edges and V is the number of nodes in the graph. 
It is assumed that s != t, s and t are connected, and that the capacities are positive integer values.
*/

int n, m, u, v, w, s, t;
vector<vector<int>> adj, cap;
vector<int> par;
int bfs(int i) {
    fill(par.begin(), par.end(), -1);
    queue<pair<int, int>> q;
    q.push({i, INF});
    par[i] = i;
    while (!q.empty()) {
        auto [c, mn] = q.front(); q.pop();
        if (!mn) continue;
        for (int j : adj[c]) {
            if (!cap[c][j] || par[j] != -1) continue;
            par[j] = c;
            if (j == t) return min(mn, cap[c][j]);
            q.push({j, min(mn, cap[c][j])});
        }
    }
    return 0;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> s >> t; // expecting a graph with n nodes and m edges, with s as the source and t as the sink
    adj.resize(n + 1);
    cap.resize(n + 1);
    par.resize(n + 1);
    fill(cap.begin(), cap.end(), vector<int>(n + 1));
    while (m--) {
        cin >> u >> v >> w; // a directed edge from u to v with capacity w
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = w;
    }
    ll flow = 0, dt = 0; // dtrent flow, dtrent residual capacity
    while (dt = bfs(s)) {
        flow += dt; // increment flow by residual capacity of augmenting path
        int c = t;
        while (c != s) {
            int p = par[c];
            cap[p][c] -= dt;
            cap[c][p] += dt;
            c = p;
        }
    }
    // no more augmenting paths, means we have the max flow
    cout << flow << "\n";
    return 0;
}