#include <bits/stdc++.h>
using namespace std;

/*
Tarjan's algorithm for finding strongly connected components (SCCs) in a directed graph.
An SCC is a subset of nodes and paths in a graph such that each node has a path to every other node in the subset.
Somewhat similar to Tarjan's bridge finding algorithm
*/

int n, m, u, v, t = 0, tin[200001], low[200001], scc[200001], cnt = 0;
vector<int> adj[200001];
stack<int> st;
void dfs(int i) {
    tin[i] = low[i] = ++t;
    st.push(i);
    for (auto &j : adj[i]) {
        if (!low[j]) dfs(j);
        low[i] = min(low[i], low[j]);
    }
    if (low[i] == tin[i]) {
        ++cnt;
        while (!st.empty()) {
            int c = st.top(); st.pop(); 
            // when we pop from stack, we can just set low to some high value to prevent it from propagating
            // alternative is setting to 0, but then we'd need to check when propagating and also have another way of keeping track of vis
            low[c] = 0x3f3f3f3f;
            scc[c] = cnt;
            if (c == i) break;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v); // add directed edge from u to v
    }
    for (int i = 1; i <= n; i++) if (!low[i]) dfs(i);
    for (int i = 1; i <= n; i++) cout << scc[i] << (i == n ? "\n" : " "); // print out which scc each node belongs to
    return 0;
}
