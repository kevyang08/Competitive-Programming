#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, a;
string s;
void solve() {
    cin >> n;
    deque<int> st[2];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        st[a].push_back(i);
        if (!a) ans += st[1].size();
    }
    cin >> s;
    cout << ans;
    for (int i = 0; i < n; i++) {
        while (!st[0].empty() && (st[1].empty() || st[1].front() > st[0].front())) st[0].pop_front();
        while (!st[1].empty() && (st[0].empty() || st[0].back() < st[1].back())) st[1].pop_back();
        if (s[i] == '1' && !st[0].empty()) {
            ans -= st[0].size();
            st[1].pop_front();
        }
        if (s[i] == '0' && !st[1].empty()) {
            ans -= st[1].size();
            st[0].pop_back();
        }
        cout << ' ' << ans;
    }
    cout << '\n';
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