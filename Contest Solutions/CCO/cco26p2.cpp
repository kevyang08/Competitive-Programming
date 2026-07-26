#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, a[5000005];
bool vis[5000005];
ll b;
pair<int, int> adj[5000005];
void dfs(int i) {
    if (i == 0 || i == n + 1) return;
    vis[i] = true;
    if (!vis[adj[i].fi]) dfs(adj[i].fi);
    if (!vis[adj[i].se]) dfs(adj[i].se);
    // cout << i << " bruh\n";
    a[i] = max(a[adj[i].fi], a[adj[i].se]) + 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    vector<pair<int, int>> st;
    st.reserve(n + 1);
    st.push_back({0, INF});
    // cout << a[0] << " " << a[n + 1] << " wtf\n";
    for (int i = 1; i <= n; i++) {
        while (st.back().se == i) st.pop_back();
        cin >> b;
        while (st.size() > 1 && i + b/(i - st[st.size() - 2].fi) >= st.back().se) st.pop_back();
        b /= i - st.back().fi;
        adj[i].fi = st.back().fi;
        adj[i].se = i + b;
        // cout << b << " " << st.top() << " " << i + b << " debug\n";
        st.push_back({i, i + b});
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? '\n' : ' ');
    return 0;
}