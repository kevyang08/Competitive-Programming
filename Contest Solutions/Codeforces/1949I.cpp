#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x[1001], y[1001], r[1001], c[1001], a, b;
vector<int> adj[1001];
bool vis[1001], ans = false;
bool dfs(int i, int p, int d) {
    bool res = true;
    vis[i] = true;
    c[i] = d;
    if (d) ++b;
    else ++a;
    for (int j : adj[i]) {
        if (j == p) continue;
        if (!vis[j]) res &= dfs(j, i, d ^ 1);
        if (c[j] == d) res = false;
    }
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> r[i];
        for (int j = 1; j < i; j++) {
            ll dx = x[i] - x[j], dy = y[i] - y[j], rt = r[i] + r[j];
            if (dx * dx + dy * dy == rt * rt) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        a = b = 0;
        bool thing = dfs(i, 0, 0);
        if (thing && a != b) ans = true;
    }
    cout << (ans ? "YES\n" : "NO\n");
    return 0;
}