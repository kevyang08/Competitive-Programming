#include <bits/stdc++.h>
using namespace std;

int t = 1, n, m, a, b, c;
vector<pair<pair<int, int>, int>> ed;
vector<int> adj[16];
bool thing[16], vis[16];
void dfs(int i, int p) {
    vis[i] = true;
    for (int j : adj[i]) {
        if (j == p) continue;
        if (!vis[j]) dfs(j, i);
        thing[i] |= thing[j];
    }
}
int solve(int j, int bits) {
    if (j == m) {
        for (int i = 1; i <= n; i++) {
            thing[i] = vis[i] = false;
            adj[i].clear();
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            if ((1 << i) & bits) {
                res += ed[i].second;
                adj[ed[i].first.first].push_back(ed[i].first.second);
                adj[ed[i].first.second].push_back(ed[i].first.first);
            }
        }
        for (int i = 1; i <= n; i++) if (adj[i].size() < 2) return 0x3f3f3f3f;
        thing[1] = true;
        dfs(1, 0);
        for (int i = 2; i <= n; i++) if (!thing[i]) return 0x3f3f3f3f;
        return res;
    }
    return min(solve(j + 1, bits), solve(j + 1, bits | (1 << j)));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    while (true) {
        cin >> n >> m;
        if (!n) break;
        ed.clear();
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            ed.push_back({{a, b}, c});
        }
        int ans = solve(0, 0);
        if (ans == 0x3f3f3f3f) cout << "There is no reliable net possible for test case " << t << ".\n";
        else cout << "The minimal cost for test case " << t << " is " << ans << ".\n";
        t++;
    }
    return 0;
}
