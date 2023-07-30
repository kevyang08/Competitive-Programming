#include <bits/stdc++.h>
using namespace std;

int n, m, k, u, v, w, id[10001][5001], d[300001];
vector<pair<pair<int, int>, pair<int, int>>> ed;
int find(int i, int j) {return id[i][j] < 0 ? j : (id[i][j] = find(i, id[i][j]));}
void join(int i, int a, int b) {
    id[i][a] += id[i][b];
    id[i][b] = a;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(id, -1, sizeof(id));
    cin >> n >> m >> k;
    ed.push_back({{0, 0}, {0, 0}});
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        ed.push_back({{w, i}, {u, v}});
    }
    sort(ed.begin(), ed.end());
    for (int i = 1; i <= m; i++) {
        int l = 1, r = k, idx = 0x3f3f3f3f;
        while (l <= r) {
            int m = (l + r)/2, a = find(m, ed[i].second.first), b = find(m, ed[i].second.second);
            if (a == b) l = m + 1;
            else {
                idx = m;
                r = m - 1;
            }
        }
        if (idx == 0x3f3f3f3f) d[ed[i].first.second] = -1;
        else {
            d[ed[i].first.second] = idx;
            join(idx, find(idx, ed[i].second.first), find(idx, ed[i].second.second));
        }
    }
    for (int i = 1; i <= m; i++) cout << d[i] << "\n";
    return 0;
}
