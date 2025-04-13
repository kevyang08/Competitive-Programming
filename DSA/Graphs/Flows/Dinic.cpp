#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
Implementation of the Dinic's algorithm that finds the max flow of a network from a source node s 
to a sink node t in O(EV^2), where E is the number of edges and V is the number of nodes in the graph. 
It is assumed that s != t, s and t are connected, and that the capacities are positive integer values.

Note: It is assumed that the input graph does not contain multiple edges. If it does, 
      change cap[u][v] = w to cap[u][v] += w;
*/

int n, m, u, v, w, s, t;
vector<vector<int>> adj, cap;
vector<int> lvl, ptr;
bool bfs() {
    fill(lvl.begin(), lvl.end(), -1);
    queue<int> q;
    q.push(s);
    lvl[s] = 0;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int j : adj[c]) {
            if (!cap[c][j] || lvl[j] != -1) continue;
            lvl[j] = lvl[c] + 1;
            q.push(j);
        }
    }
    return lvl[t] != -1;
}
int dfs(int i, int mn) {
    if (!mn) return 0;
    if (i == t) return mn;
    for (; ptr[i] < adj[i].size(); ptr[i]++) {
        int j = adj[i][ptr[i]];
        if (!cap[i][j] || lvl[i] + 1 != lvl[j]) continue;
        int dt = dfs(j, min(mn, cap[i][j]));
        if (dt) {
            cap[i][j] -= dt;
            cap[j][i] += dt;
            return dt;
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
    lvl.resize(n + 1);
    ptr.resize(n + 1); // this keeps track of the next unused edge so that for each phase, we only check O(|E|) edges in total
    fill(cap.begin(), cap.end(), vector<int>(n + 1));
    while (m--) {
        cin >> u >> v >> w; // a directed edge from u to v with capacity w
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = w;
    }
    ll flow = 0, dt = 0; // current flow, current residual capacity
    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);
        while (dt = dfs(s, INF)) {
            flow += dt; // increment flow by residual capacity of augmenting path in level graph
        }
    }
    // no more augmenting paths, means we have the max flow
    cout << flow << "\n";
    return 0;
}