#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, m, x, y;
ll ans[200005], mx[200005];
void solve() {
    cin >> n >> m;
    vector<pair<int, int>> vi;
    vector<tuple<int, int, int>> vj;
    priority_queue<int> pq;
    mx[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        vi.push_back({y, x});
        mx[i] = 0;
    }
    sort(vi.begin(), vi.end());
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        vj.push_back({y, x, i});
    }
    ll cur = 0, bruh = 0;
    for (int i = n; i >= 0; i--) {
        while (!vi.empty() && vi.back().fi >= i) {
            auto [y, x] = vi.back(); vi.pop_back();
            cur += x;
            pq.push(-x);
        }
        while (!pq.empty() && pq.size() > i + 1) {
            cur += pq.top();
            pq.pop();
        }
        if (!pq.empty() && pq.size() > i) mx[i] = max(mx[i], cur + pq.top());
        else mx[i] = max(mx[i], cur);
        bruh = max(cur, bruh);
    }
    for (int i = 1; i <= n; i++) mx[i] = max(mx[i], mx[i - 1]);
    sort(vj.begin(), vj.end());
    for (auto &[y, x, i] : vj) ans[i] = max(mx[y] + x, bruh);
    for (int i = 1; i <= m; i++) cout << ans[i] << (i == m ? "\n" : " ");
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