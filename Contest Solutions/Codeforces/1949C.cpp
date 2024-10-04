#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, u, v, in[200001], s[200001], tmp[200001];
vector<int> adj[200001];
vector<int> q[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++in[u], ++in[v];
    }
    for (int i = 1; i <= n; i++) s[i] = 1;
    for (int i = 1; i <= n; i++) if (in[i] == 1) q[1].push_back(i);
    for (int i = 1; i < n; i++) {
        for (int u : q[i]) {
            tmp[u] = s[u];
            for (int v : adj[u]) tmp[v] = s[v];
        }
        for (int u : q[i]) {
            // cout << i << " " << u << " bruh\n";

            for (int v : adj[u]) {
                if (tmp[u] > tmp[v]) continue;
                s[v] += tmp[u], --in[v];

                // cout << v << " " << in[v] << " " << s[v] << " what\n";

                if (in[v] == 1) q[s[v]].push_back(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (s[i] == n) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}