#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, m, u, v, k, id[400005], bruh[400005], cur;
vector<int> adj[400005];
vector<int> vv;
stack<int> st;
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int x, int y) {
    if (id[x = find(x)] > id[y = find(y)]) swap(x, y);
    id[x] += id[y];
    id[y] = x;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    cur = n;
    fill(id, id + n, -1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;
    vv.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> vv[i];
        bruh[vv[i]] = 1;
        --cur;
    }
    for (int i = 1; i <= n; i++) {
        if (bruh[i]) continue;
        for (const int& j : adj[i]) {
            if (bruh[j] || find(j) == find(i)) continue;
            join(i, j);
            --cur;
        }
    }
    st.push(cur);
    reverse(vv.begin(), vv.end());
    for (const int& i : vv) {
        ++cur;
        bruh[i] = 0;
        for (const int& j : adj[i]) {
            if (bruh[j] || find(j) == find(i)) continue;
            join(i, j);
            --cur;
        }
        st.push(cur);
    }
    while (!st.empty()) {
        cout << st.top() << "\n";
        st.pop();
    }
    return 0;
}