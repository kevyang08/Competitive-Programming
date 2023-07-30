#include <bits/stdc++.h>
using namespace std;

int n, m, q, p, a, b, c = 0, g[1001], adj[1001][1001];
void dfs(int i) {
    g[i] = c;
    for (int j = 1; j <= n; j++) if (adj[i][j] && g[j] == 0) dfs(j);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    while (m--) {
        for (int i = 1; i <= n; i++) {
            cin >> p;
            adj[p][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (g[i] != 0) continue;
        c++;
        dfs(i);
    }
    while (q--) {
        cin >> a >> b;
        cout << (g[a] == g[b] ? "DA" : "NE") << "\n";
    }
    return 0;
}
