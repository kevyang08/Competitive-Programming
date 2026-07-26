#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, q, k;
void solve() {
    cin >> n;
    vector<bool> vis(n + 1);
    vector<int> sz(n + 1, 1);
    vector<pair<int, int>> ed;
    vector<int> st;
    k = 2;
    st.push_back(1);
    while (true) {
        cout << "? " << k << endl;
        cin >> q;
        if (!q) break;
        vector<int> tmp(q);
        for (int i = 0; i < q; i++) cin >> tmp[i];
        for (int i = st.size() - 1; i >= 0; i--) if (i >= q || st[i] != tmp[i]) {
            vis[st[i]] = true;
            if (i) sz[st[i - 1]] += sz[st[i]];
        }
        swap(st, tmp);
        if (vis[st[0]]) {
            k += sz[st[0]];
            continue;
        }
        if (st.size() > 1) {
            int i = 0;
            while (i < q - 2 && !vis[st[i + 1]]) ++i;
            ed.push_back({st[i], st[i + 1]});
            if (vis[st[i + 1]]) k += sz[st[i + 1]];
            else ++k;
        }
        else ++k;
    }
    cout << "! " << ed.size() << endl;
    for (auto &[u, v] : ed) cout << u << " " << v << endl;
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