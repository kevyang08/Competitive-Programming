#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, dist[200001];
vector<int> adj[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        stack<int> st;
        for (int i = 1; i <= n; i++) dist[i] = 0x3f3f3f3f, adj[i].clear();
        for (int i = 1; i < n; i++) adj[i].push_back(i + 1);
        while (m--) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        dist[1] = 0;
        for (int i = 1; i < n; i++) {
            while (!st.empty() && dist[st.top()] - st.top() + i >= 0) st.pop();
            cout << (st.empty() ? 1 : 0);
            for (auto &j : adj[i]) {
                dist[j] = min(dist[j], dist[i] + 1);
                while (!st.empty() && dist[st.top()] - st.top() + i >= dist[j] - j + i) st.pop();
                st.push(j);
            }
        }
        cout << "\n";
    }
    return 0;
}