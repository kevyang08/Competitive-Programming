#include <bits/stdc++.h>
using namespace std;

int s, n, e, a, b, d, u, bruh[1600][3601], ans = 0x3f3f3f3f;
vector<vector<pair<pair<int, int>, int>>> adj(1600);
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> s >> n >> e;
    for (int i = 0; i < 1600; i++) for (int j = 0; j <= 3600; j++) bruh[i][j] = 0x3f3f3f3f;
    for (int i = 1; i <= e; i++) {
        cin >> a >> b >> d >> u;
        adj[a].push_back({{d, u}, b});
        adj[b].push_back({{d, u}, a});
    }
    priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> pq;
    pq.push({{0, 0}, 0});
    while (!pq.empty()) {
        pair p = pq.top(); pq.pop();
        for (pair i : adj[p.second]) {
            if (p.first.second + i.first.first * i.first.second <= s && p.first.first + i.first.first < bruh[i.second][p.first.second + i.first.first * i.first.second]) {
                bruh[i.second][p.first.second + i.first.first * i.first.second] = p.first.first + i.first.first;
                pq.push({{p.first.first + i.first.first, p.first.second + i.first.first * i.first.second}, i.second});
            }
        }
    }
    for (int i = 0; i <= s; i++) ans = min(ans, bruh[n - 1][i]);
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
}
