#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

/*
start with end state
dsu and small-to-large
*/

int n, m, q, p[200005], inv[200005], a, b, id[200005], thing[500005];
bool del[300005], bruh[200005];
vector<pair<int, int>> ed;
vector<pair<int, int>> queries;
vector<int> st[200005];
priority_queue<int> stp[200005], rem[200005];
vector<pair<int, int>> adj[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    ed.reserve(m + 1);
    queries.reserve(q);
    ed.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        inv[p[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        ed.push_back({a, b});
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        queries.push_back({a, b});
        if (a == 2) del[b] = 1;
    }
    queue<int> qq;
    for (int i = 1; i <= n; i++) {
        if (id[i]) continue;
        qq.push(i);
        id[i] = i;
        while (!qq.empty()) {
            const int c = qq.front(); qq.pop();
            st[i].push_back(c);
            stp[i].push(p[c]);
            for (const auto [j, idx] : adj[c]) {
                if (del[idx] || id[j]) continue;
                id[j] = i;
                qq.push(j);
            }
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        auto &[u, v] = ed[queries[i].se];
        if (queries[i].fi != 2 || id[u] == id[v]) continue;
        if (st[id[u]].size() < st[id[v]].size()) swap(u, v);
        thing[i] = id[v];
        // for (const auto j : stp[thing[i]]) stp[id[u]].insert(j);
        for (const auto j : st[thing[i]]) {
            st[id[u]].push_back(j);
            stp[id[u]].push(p[j]);
            id[j] = id[u];
        }
    }
    for (int i = 0; i < q; i++) {
        const auto &[a, b] = queries[i];
        if (a == 1) {
            if (stp[id[b]].empty()) {
                cout << "0\n";
                continue;
            }
            const int res = stp[id[b]].top();
            stp[id[b]].pop();
            while (!rem[id[b]].empty() && rem[id[b]].top() == stp[id[b]].top()) rem[id[b]].pop(), stp[id[b]].pop();
            bruh[inv[res]] = 1;
            cout << res << "\n";
        }
        else {
            if (!thing[i]) continue;
            const auto &[u, v] = ed[b];
            // assert(id[u] == id[v]);
            const int cid = id[u];
            // for (auto j : stp[thing[i]]) stp[cid].erase(j);
            for (const auto &j : st[thing[i]]) {
                if (bruh[j]) rem[thing[i]].push(p[j]);
                else rem[cid].push(p[j]);
                // st[cid].erase(j);
                id[j] = thing[i];
            }
            while (!rem[thing[i]].empty() && rem[thing[i]].top() == stp[thing[i]].top()) rem[thing[i]].pop(), stp[thing[i]].pop();
            while (!rem[cid].empty() && rem[cid].top() == stp[cid].top()) rem[cid].pop(), stp[cid].pop();
        }
    }
    return 0;
}