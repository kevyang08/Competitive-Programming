#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 1e9 + 7;

ll gcdEx(ll a, ll b, ll *x, ll *y) {
    if (a%b == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1, gcd = gcdEx(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    return gcd;
}
ll modInv(ll a, ll m) {
    ll x, y;
    gcdEx(a, m, &x, &y);
    return (x%m + m)%m;
}
ll modDiv(ll a, ll b, ll m) {
    ll c = modInv(b, m);
    return (c * a)%m;
}

int n, m, a[200001], tin[200001], tout[200001], u, v, op, t = 0;
ll p[200001];
vector<int> adj[200001];
void dfs(int i, int pa) {
    p[i] = a[i];
    tin[i] = ++t;
    for (int j : adj[i]) {
        if (j == pa) continue;
        dfs(j, i);
        p[i] = (p[i] * p[j])%M;
    }
    tout[i] = ++t;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cin >> m;
    stack<ll> st;
    vector<int> vt, vv;
    vt.push_back(1); vt.push_back(2 * n);
    vv.push_back(1);
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            if (tin[u] > tin[v]) swap(u, v);
            vt.push_back(tin[v]); vt.push_back(tout[v]);
            vv.push_back(v);
        }
        else {
            sort(vt.begin(), vt.end());
            sort(vv.begin(), vv.end(), [&](auto a, auto b) {
                return tin[a] < tin[b];
            });
            ll ans = 0;
            int j = 0;
            for (int i : vt) {
                if (j < vv.size() && tin[vv[j]] == i) {
                    if (!st.empty()) {
                        ll res = st.top(); st.pop();
                        st.push(modDiv(res, p[vv[j]], M));
                    }
                    st.push(p[vv[j]]);
                    ++j;
                }
                else {
                    ans = (ans + st.top())%M;
                    st.pop();
                }
            }
            cout << ans << "\n";
            vt.clear();
            vv.clear();
            vt.push_back(1); vt.push_back(2 * n);
            vv.push_back(1);
        }
    }
    return 0;
}