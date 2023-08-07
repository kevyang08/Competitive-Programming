#include <bits/stdc++.h>
using namespace std;

int n, s[1000001], t[1000001], idx;
vector<int> adj[1000001];
bool vis[1000001];
queue<pair<int, int>> ans;
void dfs(int i) {
    vis[i] = true;
    if (s[i] != t[i]) ans.push({i, t[i]});
    for (int j : adj[i]) if (!vis[j]) dfs(j);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i] == -1) idx = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        if (t[i] != -1) adj[t[i]].push_back(i);
    }
    if (t[idx] != -1) {
        cout << -1 << "\n";
        return 0;
    }
    dfs(idx);
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        auto p = ans.front(); ans.pop();
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
