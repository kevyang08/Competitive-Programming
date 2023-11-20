#include <bits/stdc++.h>
using namespace std;

int n, m, q, a, b, c, d, dist[101][101], dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};
set<int> bits[101][101];
char ed[4][101][101];
string s, t;
unordered_map<char, int> mp;
bool solve(int a, int b, int c, int d, int l) {
    if (l == 4) return true;
    memset(dist, 4, sizeof(dist));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) bits[i][j].clear();
    dist[a][b] = 0;
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
    pq.push({{0, 0}, {a, b}});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        auto &[dt, bt] = p.first;
        auto &[i, j] = p.second;
        for (int k = 0; k < 4; k++) {
            if (i + dr[k] < 1 || i + dr[k] > n || j + dc[k] < 1 || j + dc[k] > m) continue;
            int dtt = dt, btt = bt;
            if (!(mp[ed[k][i][j]]&btt)) {
                dtt++;
                btt |= mp[ed[k][i][j]];
            }
            if (dtt > l) continue;
            if (bits[i + dr[k]][j + dc[k]].find(btt) == bits[i + dr[k]][j + dc[k]].end()) {
                dist[i + dr[k]][j + dc[k]] = min(dist[i + dr[k]][j + dc[k]], dtt);
                bits[i + dr[k]][j + dc[k]].insert(btt);
                pq.push({{dtt, btt}, {i + dr[k], j + dc[k]}});
            }
        }
    }
    return dist[c][d] == l;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    mp['P'] = 1; mp['C'] = 2; mp['Z'] = 4; mp['N'] = 8;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (j > 1) ed[1][i][j] = s[j - 2];
            if (j < m) ed[3][i][j] = s[j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != n) cin >> s;
        for (int j = 1; j <= m; j++) {
            if (i > 1) ed[0][i][j] = t[j - 1];
            if (i < n) ed[2][i][j] = s[j - 1];
        }
        t = s;
    }
    cin >> q;
    while (q--) {
        cin >> a >> b >> c >> d;
        for (int i = 1; i <= 4; i++) {
            if (solve(a, b, c, d, i)) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
