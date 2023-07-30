#include <bits/stdc++.h>
using namespace std;

int n, h[200001], u, v;
long long c = 0, avg;
vector<vector<int>> adj(200001);
vector<vector<pair<int, long long>>> a(200001);
bool vis[200001];
stack<pair<pair<int, int>, long long>> ans;
long long dfs(int cur) {
    vis[cur] = true;
    long long res = 0;
    for (int i : adj[cur]) {
        long long temp = 0;
        if (!vis[i]) temp = dfs(i);
        if (temp < 0) a[cur].push_back({i, -temp});
        else if (temp > 0) a[i].push_back({cur, temp});
        res += temp;
    }
    return res + h[cur] - avg;
}
void tsort(int cur) {
    vis[cur] = true;
    for (pair i : a[cur]) {
        if (!vis[i.first]) tsort(i.first);
        ans.push({{cur, i.first}, i.second});
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        c += h[i];
    }
    avg = c/n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= n; i++) if (!vis[i]) tsort(i);
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        cout << ans.top().first.first << " " << ans.top().first.second << " " << ans.top().second << "\n";
        ans.pop();
    }
}
