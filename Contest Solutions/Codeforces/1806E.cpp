#include <bits/stdc++.h>
using namespace std;

/*
Important to note: It is guaranteed that xi and yi are of the same depth.
time complexity is generally O(sqrt(n)(n+n/4+n/9+...)) = O(nsqrtn)
- to avoid worst case of all depth 1 nodes (n^2), we manually do cases where depth[u] <= sqrt(n)
- for each node u such that depth[u] > sqrt(n):
    - in mp, we store the ans to the query u v for all v such that depth[u] = depth[v]
    - we also keep track of its lowest ancestor v such that depth[v] <= sqrt(n)

Ignore everything above except for important to note

Key takeaway: map and unordered_map are slow, try to use arrays wherever possible
Small takeaway: read questions carefully. the guarantee that xi and yi have the same depth makes this question
    much simpler.
*/

typedef long long ll;

const int sz = 350;

int n, q, p[100001], x, y, up[100001], idx[100001];
ll a[100001], mp[100001][sz];
vector<int> adj[100001], v[100001];
void dfs1(int i, int d) {
    idx[i] = v[d].size();
    v[d].push_back(i);
    for (int j : adj[i]) dfs1(j, d + 1);
}
void dfs2(int i, int pa, int d) {
    up[i] = pa;
    if (v[d].size() >= sz) pa = i;
    else {
        for (int j : v[d]) 
            mp[i][idx[j]] = mp[j][idx[i]] = a[i] * a[j] + (idx[p[j]] < sz ? mp[p[i]][idx[p[j]]] : 0);
    }
    for (int j : adj[i]) dfs2(j, pa, d + 1);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    while (q--) {
        cin >> x >> y;
        ll ans = 0;
        while (x) {
            ans += (idx[p[y]] < sz ? mp[p[x]][idx[p[y]]] : 0) + a[x] * a[y];
            x = up[x], y = up[y];
        }
        cout << ans << "\n";
    }
    return 0;
}