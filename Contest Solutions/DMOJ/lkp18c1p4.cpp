#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, s, e, bruh[100001];
vector<vector<pair<pair<int, int>, int>>> adj(100001);
long long d;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= 100000; i++) bruh[i] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({{i, c}, b});
        adj[b].push_back({{i, c}, a});
    }
    cin >> s >> e >> d;
    priority_queue<pair<pair<int, long long>, int>, vector<pair<pair<int, long long>, int>>, greater<pair<pair<int, long long>, int>>> pq;
    pq.push({{0, 0}, s});
    while (!pq.empty()) {
        pair p = pq.top(); pq.pop();
        for (pair i : adj[p.second]) {
            if (max(p.first.first, i.first.first) < bruh[i.second] && p.first.second + i.first.second <= d) {
                bruh[i.second] = max(p.first.first, i.first.first);
                pq.push({{bruh[i.second], p.first.second + i.first.second}, i.second});
            }
        }
    }
    cout << (bruh[e] == 0x3f3f3f3f ? -1 : bruh[e]) << "\n";
}
