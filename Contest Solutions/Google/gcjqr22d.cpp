#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, f[100001], p;
ll ans = 0;
vector<vector<pair<int, int>>> adj(100001);
int dfs(int i) {
    if (adj[i].empty()) return f[i];
    int mn = 0x3f3f3f3f, bruh;
    ll temp = 0;
    for (pair p: adj[i]) {
        bruh = dfs(p.first);
        mn = min(mn, bruh);
        temp += bruh;
    }
    temp -= mn;
    ans += temp;
    return max(f[i], mn);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n;
        ans = 0;
        for (int i = 0; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) cin >> f[i];
        for (int i = 1; i <= n; i++) {
            cin >> p;
            adj[p].push_back({i, f[i]});
        }
        ans += dfs(0);
        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}
