#include <bits/stdc++.h>
using namespace std;

int k, n, m, a, b, t, h, s, e, bruh[2001][200], ans = 0x3f3f3f3f;
vector<vector<pair<pair<int, int>, int>>> adj(2001);
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> k >> n >> m;
    for (int i = 1; i <= 2000; i++) for (int j = 0; j < 200; j++) bruh[i][j] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> t >> h;
        adj[a].push_back({{t, h}, b});
        adj[b].push_back({{t, h}, a});
    }
    cin >> s >> e;
    priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> pq;
    pq.push({{0, 0}, s});
    while (!pq.empty()) {
        pair p = pq.top(); pq.pop();
        for (pair i : adj[p.second]) {
            if (p.first.second + i.first.second < k && p.first.first + i.first.first < bruh[i.second][p.first.second + i.first.second]) {
                bruh[i.second][p.first.second + i.first.second] = p.first.first + i.first.first;
                pq.push({{p.first.first + i.first.first, p.first.second + i.first.second}, i.second});
            }
        }
    }
    for (int i = 0; i < k; i++) ans = min(ans, bruh[e][i]);
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
}
