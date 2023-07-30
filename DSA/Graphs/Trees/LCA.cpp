#include <bits/stdc++.h>
using namespace std;

int n, q, a, b, t = 0, tin[100001], h[100001], st[18][200000];
vector<int> adj[100001];
void dfs(int i, int p) {
    h[i] = h[p] + 1;
    tin[i] = t;
    st[0][t++] = h[i];
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        st[0][t++] = h[i];
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    h[0] = -1;
    dfs(1, 0);
    for (int i = 1; i < 31 - __builtin_clz(2 * n) + 1; i++) {
        for (int j = 0; j < 2 * n - (1 << (i - 1)); j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    cin >> q;
    while (q--) {
        cin >> a >> b;
        int l = min(tin[a], tin[b]), r = max(tin[a], tin[b]) + 1, i = 31 - __builtin_clz(r - l);
        cout << h[a] + h[b] - 2 * min(st[i][l], st[i][r - (1 << i)]) << "\n";
    }
    return 0;
}
