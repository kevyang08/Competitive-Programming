#include <bits/stdc++.h>
using namespace std;

int n, x[100001], y[100001], w, a, b, in[100001], ans = 0, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // in[] keeps track of edges connected to each point that haven't been used yet
vector<pair<pair<int, int>, int>> v; // to sort the points by x-coord, then by y-coord
vector<pair<int, int>> adj[100001]; // adjacency list containing index of point and index of edge
bool vis[200001], used[200001], up[200001];
void dfs(int i, int st, int d = 0) {
    for (int k = (d - 1 + 4)%4; k < (d - 1 + 4)%4 + 4; k++) {
        for (auto p : adj[i]) {
            if (used[p.second]) continue;
            int cx = x[p.first] - x[i], cy = y[p.first] - y[i];
            if (cx) cx /= abs(cx);
            else cy /= abs(cy);
            if (cx == dx[k%4] && cy == dy[k%4]) {
                if (vis[p.second]) {
                    ans++;
                    up[p.second] = true;
                }
                else {
                    vis[p.second] = true;
                    in[i]--; in[p.first]--;
                }
                if (p.first != st) dfs(p.first, st, k%4);
                used[p.second] = true;
                return;
            }
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        v.push_back({{x[i], y[i]}, i});
    }
    cin >> w;
    for (int i = 1; i <= w; i++) {
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        in[a]++; in[b]++;
    }
    sort(v.begin(), v.end());
    // remember to keep track of starting point later on
    // if an edge is visited twice, then it will be up at the end
    for (int i = 0; i < n; ) {
        if (!in[v[i].second]) {
            i++;
            continue;
        }
        dfs(v[i].second, v[i].second);
    }
    cout << ans << "\n";
    for (int i = 1; i <= w; i++) if (up[i]) cout << i << "\n";
    return 0;
}
