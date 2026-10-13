#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, a, b, u, v, dp[300005];
vector<int> path, cur;
vector<int> adj[300005];
void get_path(int i, int pa) {
    cur.push_back(i);
    if (i == b) for (int j : cur) path.push_back(j);
    for (int j : adj[i]) if (j != pa) get_path(j, i);
    cur.pop_back();
    return;
}
void dfs(int i, int pa, int thing) {
    dp[i] = 0;
    vector<int> v;
    for (int j : adj[i]) {
        if (j == pa || j == thing) continue;
        dfs(j, i, thing);
        v.push_back(dp[j]);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int j = 0; j < v.size(); j++) dp[i] = max(dp[i], v[j] + j + 1);
}
int get_ans(int idx) {
    dfs(a, 0, path[idx]);
    dfs(b, 0, path[idx - 1]);
    return max(dp[a], dp[b]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout << fixed << setprecision(9);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_path(a, 0);
    int l = 1, r = path.size() - 1;
    while (r - l > 1) {
        int m = (l + r)/2;
        dfs(a, 0, path[m]);
        dfs(b, 0, path[m - 1]);
        if (dp[a] < dp[b]) l = m;
        else r = m;
    }
    cout << min(get_ans(l), get_ans(r)) << "\n";
    return 0;
}