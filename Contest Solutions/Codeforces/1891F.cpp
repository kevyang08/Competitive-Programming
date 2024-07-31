#include <bits/stdc++.h>
using namespace std;

int t, q, op, sz, v;
long long x, bit[500001], ans[500001];
vector<int> adj[500001];
vector<pair<int, long long>> vq[500001];
void update(int i, long long v) {
    for (; i > 0; i -= (i & -i)) bit[i] += v;
}
long long query(int i) {
    long long res = 0;
    for (; i <= q; i += (i & -i)) res += bit[i]; // why can't it be sz??
    return res;
}
void dfs(int i) {
    for (auto &[a, b] : vq[i]) update(a, b);
    ans[i] = query(i);
    for (auto &j : adj[i]) dfs(j);        
    for (auto &[a, b] : vq[i]) update(a, -b);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        sz = 1;
        cin >> q;
        for (int i = 1; i <= q; i++) adj[i].clear(), vq[i].clear(), bit[i] = 0, ans[i] = 0;
        for (int i = 1; i <= q; i++) {
            cin >> op >> v;
            if (op == 1) adj[v].push_back(++sz);
            else {
                cin >> x;
                vq[v].push_back({sz, x});
            }
        }
        dfs(1);
        for (int i = 1; i <= sz; i++) cout << ans[i] << (i == sz ? "\n" : " ");
    }
    return 0;
}