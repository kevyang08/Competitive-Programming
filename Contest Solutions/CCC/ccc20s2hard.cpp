#include <bits/stdc++.h>
using namespace std;

int adj[16000001], lo[16000001], hi[16000001];
bool vis[16000001];
int MN;
bool bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) [[likely]] {
        int c = q.front(); q.pop();
        if (!lo[c]) continue;
        for (int j = lo[c]; j < hi[c]; j++) {
            const int v = adj[j];
            if (v == MN) [[unlikely]] return true;
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return false;
}
bool can_escape(int M, int N, std::vector<std::vector<int>> v) {
    MN = M * N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i][j] <= MN) {
                ++hi[i * j];
            }
        }
    }
    int cur = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i][j] > MN || lo[i * j]) continue;
            lo[i * j] = cur;
            cur += hi[i * j];
            hi[i * j] = cur;
        }
    }
    {
        int idx[16000001];
        memcpy(idx, lo, sizeof(int) * (MN + 1));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (v[i][j] <= MN) {
                    adj[idx[i * j]++] = move(v[i][j]);
                }
            }
        }
    }
    return bfs();   
}