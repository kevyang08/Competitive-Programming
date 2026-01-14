#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, p[100005], id[100005];
ll ans[100005];
priority_queue<pair<int, int>> pq;
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int u, int v) {
    if (id[u = find(u)] > id[v = find(v)]) swap(u, v);
    id[u] += id[v];
    id[v] = u;
}
void solve() {
    cin >> n;
    fill(id, id + n + 1, -1);
    ans[n] = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i < n; i++) pq.push({abs(p[i] - p[i + 1]), i});
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = ans[i + 1];
        while (!pq.empty() && pq.top().fi >= i) {
            int u = pq.top().se; pq.pop();
            ans[i] += (ll)id[find(u)] * id[find(u + 1)];
            join(u, u + 1);
        }
    }
    for (int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}