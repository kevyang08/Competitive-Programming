#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, dist[2][1000][1000];
set<int> st[1000];
queue<tuple<int, int, int>> q;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) st[i].clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[0][i][j] = dist[1][i][j] = 0x3f3f3f3f;
                cin >> a;
                if (a) st[j].insert(i);
            }
        }
        q.push({0, 0, 0});
        dist[0][0][0] = 0;
        while (!q.empty()) {
            auto [a, b, c] = q.front(); q.pop();

            // cout << a << " " << b << " " << dist[a][b] << " bruh\n";

            if (b < m - 1 && dist[c ^ 1][a][b + 1] > dist[c][a][b] + 1 && st[b + 1].find((dist[c][a][b] + 1 + a)%n) == st[b + 1].end()) {
                dist[c ^ 1][a][b + 1] = dist[c][a][b] + 1;
                q.push({a, b + 1, c ^ 1});
            }
            if (dist[c ^ 1][(a - 1 + n)%n][b] > dist[c][a][b] + 1) {
                dist[c ^ 1][(a - 1 + n)%n][b] = dist[c][a][b] + 1;
                q.push({(a - 1 + n)%n, b, c ^ 1});
            }
            if (dist[c ^ 1][(a + 1)%n][b] > dist[c][a][b] + 1 && st[b].find((dist[c][a][b] + 1 + a)%n) == st[b].end() && st[b].find((dist[c][a][b] + 2 + a)%n) == st[b].end()) {
                dist[c ^ 1][(a + 1)%n][b] = dist[c][a][b] + 1;
                q.push({(a + 1)%n, b, c ^ 1});
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 2; i++) ans = min(ans, dist[i][n - 1][m - 1]);
        cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
    }
    return 0;
}