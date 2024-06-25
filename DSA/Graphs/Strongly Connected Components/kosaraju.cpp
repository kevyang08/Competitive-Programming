#include <bits/stdc++.h>
using namespace std;

/*
Kosaraju's algorithm for finding strongly connected components (SCCs) in a connected directed graph.
An SCC is a subset of nodes and paths in a graph such that each node has a path to every other node in the subset.
Overall simpler to code, but slightly higher constant factor than Tarjan's
*/

/*
For Kosaraju's, it is actually important to transpose the graph and process the nodes in decreasing order of tout.
If we process nodes in increasing order of tout, nodes that have lower tout might be part of a SCC that wasn't 
    fully processed before a node with a larger tout. However, if we take the maximum tout in each SCC, we can see that
    SCC b is only reachable by SCC a if max(tout[a]) > max(tout[b])
Thus, when we process nodes in reverse order of tout on a transposed graph, we can guarantee that we will only process
    one SCC at a time, which happens to be in reverse topological order

*note: tout is basically when the current node was popped from call stack
*/

int n, m, u, v, scc[200001], cnt = 0;
vector<int> adj[200001], adjr[200001];
vector<int> order;
bool vis[200001];
void dfs1(int i) {
    vis[i] = true;
    for (auto j : adj[i]) if (!vis[j]) dfs1(j);
    order.push_back(i);
}
void dfs2(int i, int c) {
    scc[i] = c;
    for (int j : adjr[i]) if (!scc[j]) dfs2(j, c);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v); // add directed edge from u to v
        adjr[v].push_back(u); // add a directed edge in the transposed graph from v to u
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    reverse(order.begin(), order.end());
    for (int i : order) if (!scc[i]) dfs2(i, ++cnt);
    for (int i = 1; i <= n; i++) cout << scc[i] << (i == n ? "\n" : " "); // print out which scc each node belongs to
    return 0;
}
