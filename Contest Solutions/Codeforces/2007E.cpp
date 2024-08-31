#include <bits/stdc++.h>
using namespace std;

int t, n, p, x, c[200005], idx[200005], cur, cnt;
long long w, y;
vector<int> adj[200005];
void dfs(int i) {
    if (i == cur) cur = cur%n + 1;
    if (cur ^ 1) ++c[cur];
    for (int j : adj[i]) {
        dfs(j);
        idx[j] = cur;
        ++c[cur];
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> w;
        cur = 1, cnt = n;
        long long ans = w * n;
        for (int i = 1; i <= n; i++) idx[i] = 0, c[i] = 0, adj[i].clear();
        for (int i = 2; i <= n; i++) {
            cin >> p;
            adj[p].push_back(i);
        }
        dfs(1);
        while (--n) {
            cin >> x >> y;
            ans -= w * cnt;
            w -= y;
            --c[x], --c[idx[x]];
            if (!c[x]) --cnt;
            if (!c[idx[x]]) --cnt;
            ans += (y << 1) + w * cnt;
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}