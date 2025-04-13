#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
Implementation of the Push-Relabel algorithm with greatest height optimization that finds the max flow 
of a network from a source node s to a sink node t in O(V^3), where V is the number of nodes in the graph. 
It is assumed that s != t, s and t are connected, and that the capacities are positive integer values.

Note: It is assumed that the input graph does not contain multiple edges. If it does, 
      change cap[u][v] = w to cap[u][v] += w;
*/

int n, m, u, v, w, s, t;
vector<vector<int>> cap, flow;
vector<int> h, ex;
void push(int i, int j) {
    int d = min(ex[i], cap[i][j] - flow[i][j]);
    ex[j] += d;
    ex[i] -= d;
    flow[i][j] += d;
    flow[j][i] -= d;
}
vector<int> find_mx() {
    vector<int> mx;
    for (int i = 1; i <= n; i++) {
        if (i != s && i != t && ex[i] > 0) {
            if (!mx.empty() && h[i] > h[mx[0]]) mx.clear();
            if (mx.empty() || h[i] == h[mx[0]]) mx.push_back(i);
        }
    }
    return mx;
}
void relabel(int i) {
    int d = INF;
    for (int j = 1; j <= n; j++) if (cap[i][j] > flow[i][j]) d = min(d, h[j]);
    if (d != INF) h[i] = d + 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> s >> t; // expecting a graph with n nodes and m edges, with s as the source and t as the sink
    h.resize(n + 1); // initialize all heights to 0 except h[s]
    h[s] = n;
    ex.resize(n + 1); // initialize all excess to 0 except ex[s]
    ex[s] = INF;
    cap.assign(n + 1, vector<int>(n + 1));
    flow.assign(n + 1, vector<int>(n + 1));
    while (m--) {
        cin >> u >> v >> w; // a directed edge from u to v with capacity w
        cap[u][v] = w;
    }
    for (int i = 1; i <= n; i++) if (i != s) push(s, i); // push flow to all outgoing edges from s
    vector<int> cur;
    while (!(cur = find_mx()).empty()) { // find all nodes with the maximum height that still have excess incoming flow
        for (int i : cur) {
            bool pushed = false;
            for (int j = 1; j <= n && ex[i]; j++) {
                if (cap[i][j] - flow[i][j] > 0 && h[i] == h[j] + 1) { // push flow 'downwards'
                    push(i, j);
                    pushed = true;
                }
            }
            if (!pushed) { // increase height
                relabel(i);
                break;
            }
        }
    }
    // no more nodes other than t have excess flow, meaning we have found a valid max flow
    // excess flow into t is equal to the flow amount
    cout << ex[t] << "\n";
    return 0;
}