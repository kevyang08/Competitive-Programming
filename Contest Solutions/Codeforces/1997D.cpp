#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], p, mn[200001];
vector<int> adj[200001];
void dfs(int i) {
    if (!adj[i].size()) {
        mn[i] = a[i];
        return;
    }
    for (int j : adj[i]) {
        dfs(j);
        mn[i] = min(mn[i], mn[j]);
    }
    if (a[i] < mn[i]) mn[i] = (a[i] + mn[i])/2;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        fill(mn, mn + n + 1, 0x3f3f3f3f);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2; i <= n; i++) {
            cin >> p;
            adj[p].push_back(i);
        }
        dfs(1);
        int ans = 0x3f3f3f3f;
        for (int i : adj[1]) ans = min(ans, mn[i]);
        cout << a[1] + ans << "\n";
    }
    return 0;
}