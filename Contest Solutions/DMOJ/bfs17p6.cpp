#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, l, w, h, p, bruh[100005], bit[5005][5005];
ll thing[100005];
pair<ll, int> query(int r, int c) {
    ll mx = 0;
    int res = 0;
    for (; r <= 5000; r += (r & -r)) {
        for (int j = c; j <= 5000; j += (j & -j)) {
            if (thing[bit[r][j]] < mx) continue;
            res = bit[r][j];
            mx = thing[res];
        }
    }
    return {mx, res};
}
void update(int r, int c, int idx) {
    for (; r > 0; r -= (r & -r)) {
        for (int j = c; j > 0; j -= (j & -j)) {
            if (thing[idx] < thing[bit[r][j]]) continue;
            bit[r][j] = idx;
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    vector<array<int, 5>> v;
    ll cur = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l >> w >> h >> p;
        if (l < w) swap(l, w);
        v.push_back({h, l, w, p, i});
    }
    sort(v.begin(), v.end(), greater<array<int, 5>>());
    for (auto &[_, l, w, p, idx] : v) {
        auto [mx, res] = query(l, w);
        bruh[idx] = res;
        thing[idx] = mx + p;
        update(l, w, idx);
        if (mx + p > cur) {
            cur = mx + p;
            ans = idx;
        }
    }
    stack<int> st;
    while (ans) {
        st.push(ans);
        ans = bruh[ans];
    }
    cout << cur << "\n";
    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
    return 0;
}