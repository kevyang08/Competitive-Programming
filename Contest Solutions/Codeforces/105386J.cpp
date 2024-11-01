#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
post-submission: wtf map is so much faster than unordered_map???
*/

int t, n, m, k, u, v, c, l, a, b, ans[500001];
vector<tuple<int, int, int>> adj[500001];
priority_queue<pair<ll, int>> pq[500001];
map<int, ll> dist[500001];
map<int, ll> tdist;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) adj[i].clear(), dist[i].clear(), ans[i] = 0;
        ans[1] = 1;
        for (int i = 1; i <= m; i++) dist[1][i] = 0;
        for (int i = 1; i <= m; i++) while (!pq[i].empty()) pq[i].pop();
        for (int i = 1; i <= m; i++) pq[i].push({0LL, 1});
        while (m--) {
            cin >> u >> v >> c >> l;
            adj[u].push_back({v, c, l});
            adj[v].push_back({u, c, l});
        }
        while (k--) {
            cin >> a >> b;
            stack<pair<int, int>> temp;
            stack<int> st;
            while (!pq[a].empty() && -pq[a].top().first <= b) {
                // ll d;
                // int cur;
                // if (!pq[a].empty() && (temp.empty() || -pq[a].top().first <= -get<0>(temp.top()))) {
                //     d = -pq[a].top().first, cur = pq[a].top().second;
                //     pq[a].pop();
                // }
                // else {
                //     d = -get<0>(temp.top()), cur = get<2>(temp.top());
                //     temp.pop();
                // }
                auto [d, cur] = pq[a].top(); pq[a].pop();
                d = -d;

                // cout << cur << " " << d << " " << a << " bruh\n";

                if (tdist.find(cur) != tdist.end() && d > tdist[cur]) continue;
                ans[cur] = true;
                st.push(cur);
                for (auto &[x, y, z] : adj[cur]) {
                    if (y != a) {
                        if (dist[x].find(y) != dist[x].end() && dist[x][y] <= z) continue;
                        dist[x][y] = z;
                        pq[y].push({-z, x});
                    }
                    else {
                        if (d + z <= b) {
                            if (tdist.find(x) != tdist.end() && tdist[x] <= d + z || dist[x].find(a) != dist[x].end() && !dist[x][a]) continue;
                            tdist[x] = d + z;
                            pq[a].push({-(d + z), x});
                        }
                        else {
                            if (dist[x].find(a) != dist[x].end() && dist[x][a] <= z) continue;
                            dist[x][a] = z;
                            temp.push({z, x});
                        }
                    }
                }
            }
            tdist.clear();
            while (!st.empty()) {
                dist[st.top()][a] = 0;
                st.pop();
            }
            while (!temp.empty()) {
                auto [w, v] = temp.top();
                pq[a].push({-w, v});
                if (dist[v].find(a) == dist[v].end() || dist[v][a] < w) dist[v][a] = w;
                // auto [d, w, v] = temp.top();
                // dist[v][a] = -w;
                temp.pop();
                // pq[a].push({w, v});
            }
            // cout << ans[3] << " bruh\n";
        }
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << "\n";
    }
    return 0;
}