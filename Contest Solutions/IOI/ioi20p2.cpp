#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int construct(std::vector<std::vector<int>> p) {
    int n = p.size();
    vector<bool> vis(n);
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        if (p[i][i] != 1) return 0;
        for (int j = 0; j < n; j++) if (p[i][j] != p[j][i] || p[i][j] == 3) return 0;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        bool v = false;
        queue<int> q;
        vector<int> idx(n, INF);
        vector<int> st;
        vector<bool> used(n);
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            st.push_back(c);
            used[c] = true;
            for (int j = 0; j < n; j++) {
                if (!p[c][j]) continue;
                if (p[c][j] == 2) v = true;
                if (p[c][j] == 1 && idx[j] == INF) idx[j] = c;
                if (vis[j]) continue;
                q.push(j);
                vis[j] = true;
            }
        }
        for (int c : st) {
            for (int j = 0; j < n; j++) {
                if (!p[c][j] && used[j]) return 0;
                else if (p[c][j] == 1 && idx[c] != idx[j]) return 0;
                else if (p[c][j] == 2 && idx[c] == idx[j]) return 0;
            }
        }
        int prv = i, cnt = 1;
        for (int j : st) {
            if (j == i) continue;
            if (idx[j] == j) adj[prv][j] = adj[j][prv] = 1, prv = j, ++cnt;
            else adj[j][idx[j]] = adj[idx[j]][j] = 1;
        }
        if (v && cnt < 3) return 0;
        if (v) adj[prv][i] = adj[i][prv] = 1;
    }
    build(adj);
    return 1;
}