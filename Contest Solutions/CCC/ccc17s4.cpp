#include <bits/stdc++.h>
using namespace std;

int n, m, d, a, b, c, bruh = 0, ans = 0, mx = 0, id[100001];
bool used[200000];
int find(int x) {return id[x] < 0 ? x : (id[x] = find(id[x]));}
void join(int x, int y) {
    id[x = find(x)] += id[y = find(y)];
    id[y] = x;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector<pair<pair<int, int>, pair<int, int>>> v;
    cin >> n >> m >> d;
    memset(id, -1, 400004);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v.push_back({{c, (i < n - 1) ^ 1}, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        if (find(v[i].second.first) != find(v[i].second.second)) {
            join(v[i].second.first, v[i].second.second);
            mx = v[i].first.first;
        }
        else ans += v[i].first.second ^ 1;
    }
    memset(id, -1, 400004);
    for (int i = 0; i < m; i++) {
        if (find(v[i].second.first) != find(v[i].second.second)) {
            if (v[i].first.first < mx || (v[i].first.first == mx && v[i].first.second ^ 1)) join(v[i].second.first, v[i].second.second);
            else if (v[i].first.first <= d && v[i].first.second ^ 1) bruh = 1;
        }
    }
    cout << ans - bruh << "\n";
}
