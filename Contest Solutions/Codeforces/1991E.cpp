#include <bits/stdc++.h>
using namespace std;

int t, n, m, u, v, bruh[10001];
vector<int> adj[10001], v1, v2;
bool odd;
void dfs(int i, int p, int d) {
    if (d%2) v1.push_back(i);
    else v2.push_back(i);
    bruh[i] = d;
    for (auto &j : adj[i]) {
        if (j == p) continue;
        if (!bruh[j]) dfs(j, i, d + 1);
        else {
            if (bruh[i]%2 == bruh[j]%2) odd = true;
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
        cin >> n >> m;
        odd = false;
        fill(bruh, bruh + n + 1, 0);
        v1.clear(); v2.clear();
        for (int i = 1; i <= n; i++) adj[i].clear();
        while (m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0, 1);
        if (odd) {
            cout << "Alice" << endl;
            for (int i = 1; i <= n; i++) {
                cout << "1 2" << endl;
                cin >> u >> v;
            }
        }
        else {
            cout << "Bob" << endl;
            for (int i = 1; i <= n; i++) {
                cin >> u >> v;
                if ((u == 1 || v == 1) && !v1.empty()) {
                    cout << v1.back() << " 1" << endl;
                    v1.pop_back();
                }
                else if ((u == 2 || v == 2) && !v2.empty()) {
                    cout << v2.back() << " 2" << endl;
                    v2.pop_back();
                }
                else if ((u != 1 || v != 1) && v1.empty()) {
                    cout << v2.back() << " " << (u != 1 ? u : v) << endl;
                    v2.pop_back();
                }
                else {
                    cout << v1.back() << " " << (u != 2 ? u : v) << endl;
                    v1.pop_back();
                }
            }
        }
    }
    return 0;
}