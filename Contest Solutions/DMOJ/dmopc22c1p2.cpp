#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, a, b, mn = INT_MAX;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<pair<int, int>>> dist1(n + 1), distn(n + 1);
    queue<int> q;
    int arr[n + 1], dist[2][n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dist[0][i] = dist[1][i] = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int k = 0; k < 2; k++) {
        q.push((k ? n : 1));
        dist[k][(k ? n : 1)] = 0;
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            for (int i : adj[c]) {
                if (dist[k][c] + 1 < dist[k][i]) {
                    dist[k][i] = dist[k][c] + 1;
                    q.push(i);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[0][i] != INT_MAX) dist1[arr[i]].pb({dist[0][i], i});
        if (dist[1][i] != INT_MAX) distn[arr[i]].pb({dist[1][i], i});
    }
    for (int i = 1; i <= n; i++)    {
        if (dist1[i].size() == 0 || distn[i].size() == 0) continue;
        sort(dist1[i].begin(), dist1[i].end());
        sort(distn[i].begin(), distn[i].end());
        if (dist1[i][0].second != distn[i][0].second) mn = min(mn, dist1[i][0].first + distn[i][0].first);
        if (dist1[i].size() > 1 && dist1[i][1].second != distn[i][0].second) mn = min(mn, dist1[i][1].first + distn[i][0].first);
        if (distn[i].size() > 1 && dist1[i][0].second != distn[i][1].second) mn = min(mn, dist1[i][0].first + distn[i][1].first);
        if (dist1[i].size() > 1 && distn[i].size() > 1 && dist1[i][1].second != distn[i][1].second) mn = min(mn, dist1[i][1].first + distn[i][1].first);
    }
    cout << (mn == INT_MAX ? -1 : mn) << "\n";
}
