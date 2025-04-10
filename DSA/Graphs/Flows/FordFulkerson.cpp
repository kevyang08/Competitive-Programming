#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
Implementation of the Ford-Fulkerson algorithm that finds the max flow of a network from a source node s 
to a sink node t in O(Ef), where E is the number of edges in the graph and f is the maximum possible flow. 
It is assumed that s != t, s and t are connected, and that the capacities are positive integer values.

Note that although this implementation uses an adjacency list, using an adjacency matrix would be simpler
*/

/*
*NOTE: This has not been properly stress tested yet, it has only been lightly tested on CSES
*/

struct edge {
    int c, v;
    edge *rev;
    edge(int w, int to) : c{w}, v{to} {}
};
int n, m, u, v, w, s, t;
vector<vector<edge*>> adj;
vector<bool> vis;
int dfs(int i, int mn) {
    if (!mn) return 0;
    if (i == t) return mn;
    vis[i] = true;
    for (auto e : adj[i]) {
        if (!(e -> c) || vis[e -> v]) continue;
        int dt = dfs(e -> v, min(mn, e -> c));
        if (dt) { // if we have found an augmenting path
            e -> c -= dt;
            e -> rev -> c += dt;
            vis[i] = false;
            return dt;
        }
    }
    vis[i] = false;
    return 0;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> s >> t; // expecting a graph with n nodes and m edges, with s as the source and t as the sink
    adj.resize(n + 1);
    vis.resize(n + 1);
    while (m--) {
        cin >> u >> v >> w; // a directed edge from u to v with capacity w
        edge *a = new edge(w, v), *b = new edge(0, u);
        a -> rev = b; b -> rev = a;
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    ll flow = 0, dt = INF; // current flow, current residual capacity
    while (dt = dfs(s, INF)) {
        flow += dt; // increment flow by residual capacity of augmenting path
    }
    // no more augmenting paths, means we have the max flow
    cout << flow << "\n";
    return 0;
}