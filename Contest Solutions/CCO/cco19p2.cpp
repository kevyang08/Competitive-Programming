#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> ob, adj;
int n, m, c = 0, d[1000001], pr[1000001], po[1000001], dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
vector<map<int, int>> p;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(d, 0x3f3f3f3f, sizeof(d));
    cin >> n >> m;
    int num[n + 1][m], ans[n + 1][m];
    string grid[n + 1];
    char bruh[n + 1][m];
    memset(num, -1, sizeof(num));
    memset(ans, 0, sizeof(ans));
    memset(bruh, '.', sizeof(bruh));
    for (int i = 0; i < n; i++) cin >> grid[i];
    d[0] = 0;
    ob.push_back(vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        num[n][i] = 0;
        pr[i] = n; po[i] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '#' || num[i][j] != -1) continue;
            ob.push_back(vector<pair<int, int>>());
            c++;
            queue<pair<int, int>> q;
            q.push({i, j});
            num[i][j] = c;
            while (!q.empty()) {
                pair p = q.front(); q.pop();
                ob[c].push_back(p);
                for (int k = 0; k < 4; k++) {
                    if (p.first + dr[k] >= 0 && p.first + dr[k] < n && p.second + dc[k] >= 0 && p.second + dc[k] < m && grid[p.first + dr[k]][p.second + dc[k]] == '#' && num[p.first + dr[k]][p.second + dc[k]] == -1) {
                        q.push({p.first + dr[k], p.second + dc[k]});
                        num[p.first + dr[k]][p.second + dc[k]] = c;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= c; i++) p.push_back(map<int, int>());
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '#') continue;
            if (num[i][j] != po[j] && (p[num[i][j]].find(po[j]) == p[num[i][j]].end() || pr[j] - i - 1 < p[num[i][j]][po[j]])) p[num[i][j]].insert_or_assign(po[j], pr[j] - i - 1);
            pr[j] = i;
            po[j] = num[i][j];
        }
    }
    for (int i = 0; i <= c; i++) adj.push_back(vector<pair<int, int>>());
    for (int i = 1; i <= c; i++) for (auto it = p[i].begin(); it != p[i].end(); it++) adj[it->first].push_back({i, it->second});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pair cur = pq.top(); pq.pop();
        for (pair p : ob[cur.first]) ans[p.first][p.second] = d[cur.first];
        for (pair i : adj[cur.first]) {
            if (cur.second + i.second < d[i.first]) {
                d[i.first] = cur.second + i.second;
                pq.push({i.first, d[i.first]});
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '#') bruh[i + ans[i][j]][j] = '#';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << bruh[i][j];
        cout << "\n";
    }
}
// its a miracle my code even works
/*
test cases:
1. 
7 6
######
.....#
#..#.#
#....#
#..###
#.....
#.....

......
######
#....#
#....#
#..#.#
#..###
#.....

2.
5 5
.####
#....
##...
....#
..###

.....
.....
.####
#...#
#####
*/
