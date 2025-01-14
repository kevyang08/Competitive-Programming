#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// bipartite matching with ford-fulkerson

int n, m, k, a, adj[205][205];
bool vis[205], ans[205];
int dfs(int i, int mn) {
    if (!mn) return 0;
    if (i == n + m + 1) return mn;
    vis[i] = true;
    for (int j = 2; j <= n + m + 1; j++) {
        if (!adj[i][j] || vis[j]) continue;
        int cur = dfs(j, min(mn, adj[i][j]));
        if (cur) {
            adj[i][j] -= cur;
            adj[j][i] += cur;
            vis[i] = false;
            ans[j] = false;
            return cur;
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[0][i] = 1;
        cin >> k;
        while (k--) {
            cin >> a;
            if (i == 1) ans[n + a] = true;
            else if (ans[n + a]) adj[i][n + a] = 1;
        }
    }
    for (int i = 1; i <= m; i++) adj[n + i][n + m + 1] = 1;
    int mx = 0, cur = INF, cnt = 0;
    while (cur) {
        cur = dfs(0, INF);
        mx += cur;
    }
    for (int i = 1; i <= n + m + 1; i++) if (ans[i]) ++cnt;
    cout << cnt << "\n";
    return 0;
}