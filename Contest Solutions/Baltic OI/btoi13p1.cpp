#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, q, p[100005], op, x, rt, mn[100005], up[18][100005], bruh[100005], tin[100005], t = 0;
vector<int> adj[100005];
set<pair<int, int>> st;
void dfs(int i) {
    mn[i] = i;
    up[0][i] = p[i];
    for (int j = 1; j < 18; j++) up[j][i] = up[j - 1][up[j - 1][i]];
    for (int j : adj[i]) {
        dfs(j);
        mn[i] = min(mn[i], mn[j]);
    }
}
void dfs2(int i) {
    vector<pair<int, int>> tmp;
    for (int j : adj[i]) tmp.push_back({mn[j], j});
    sort(tmp.begin(), tmp.end());
    for (auto [_, j] : tmp) dfs2(j);
    tin[i] = ++t;
    st.insert({tin[i], i});
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i]) adj[p[i]].push_back(i);
        else rt = i;
    }
    dfs(rt);
    dfs2(rt);
    while (q--) {
        cin >> op >> x;
        if (op == 1) {
            int ans = -1;
            while (x--) {
                auto [_, u] = *st.begin();
                st.erase(st.begin());
                bruh[u] = 1;
                ans = u;
            }
            cout << ans << "\n";
        }
        else {
            int ans = 0;
            for (int i = 17; i >= 0; i--) if (bruh[up[i][x]]) {
                ans += (1 << i);
                x = up[i][x];
            }
            st.insert({tin[x], x});
            bruh[x] = 0;
            cout << ans << "\n";
        }
    }
    return 0;
}