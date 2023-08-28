#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, q, h, v[100005], d, b, m, in[100005], out[100005], t = 0;
long long ans[100005], tree[800005], lazy[800005];
vector<int> adj[100005];
vector<pair<int, pair<int, int>>> vq;
stack<pair<int, int>> st;
void dfs(int i) {
    in[i] = ++t;
    for (int j : adj[i]) dfs(j);
    out[i] = ++t;
}
void pushDown(int l, int r, int idx) {
    if (lazy[idx]) {
        if (l != r) {
            tree[idx << 1] += lazy[idx];
            tree[idx << 1 | 1] += lazy[idx];
            lazy[idx << 1] += lazy[idx];
            lazy[idx << 1 | 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}
void update(int l, int r, int ql, int qr, int idx, int v) {
    pushDown(l, r, idx);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        tree[idx] += v;
        lazy[idx] += v;
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, ql, qr, idx << 1, v);
    update(m + 1, r, ql, qr, idx << 1 | 1, v);
    tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
}
long long query(int l, int r, int ql, int qr, int idx) {
    pushDown(l, r, idx);
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return tree[idx];
    int m = (l + r) >> 1;
    return max(query(l, m, ql, qr, idx << 1), query(m + 1, r, ql, qr, idx << 1 | 1));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h >> v[i] >> d;
        while (!st.empty() && st.top().se <= h) st.pop();
        if (!st.empty()) adj[st.top().fi].push_back(i);
        st.push({i, h});
        vq.push_back({d, {0, i}});
    }
    for (int i = 1; i <= n; i++) if (!in[i]) dfs(i);
    for (int i = 1; i <= q; i++) {
        cin >> b >> m;
        vq.push_back({m, {i, b}});
    }
    sort(vq.begin(), vq.end());
    for (auto p : vq) {
        int op = p.se.fi, i = p.se.se;
        if (op) ans[op] = v[i] + query(1, t, in[i], out[i], 1) - query(1, t, in[i], in[i], 1);
        else update(1, t, in[i], out[i], 1, v[i]);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
