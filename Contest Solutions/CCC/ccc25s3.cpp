#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m, q, c[200001], p[200001], op, a, b;
multiset<int, greater<int>> ms[200001];
ll ans = 0;
multiset<int> st;
multiset<int, greater<int>> mx;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> p[i];
        ms[c[i]].insert(p[i]);
    }
    for (int i = 1; i <= m; i++) {
        ans += *ms[i].begin();
        st.insert(*ms[i].begin());
        if (ms[i].size() > 1) mx.insert(*(++ms[i].begin()));
    }
    mx.insert(0);
    cout << max(ans, ans - *st.begin() + *mx.begin()) << "\n";
    while (q--) {
        cin >> op >> a >> b;
        if (p[a] == *ms[c[a]].begin()) {
            st.extract(p[a]);
            ans -= p[a];
            if (ms[c[a]].size() > 1) {
                ans += *(++ms[c[a]].begin());
                mx.extract(*(++ms[c[a]].begin()));
                st.insert(*(++ms[c[a]].begin()));
            }
            if (ms[c[a]].size() > 2) mx.insert(*(++(++ms[c[a]].begin())));
        }
        else if (ms[c[a]].size() > 1 && p[a] == *(++ms[c[a]].begin())) {
            mx.extract(p[a]);
            if (ms[c[a]].size() > 2) mx.insert(*(++(++ms[c[a]].begin())));
        }
        ms[c[a]].extract(p[a]);
        if (op == 1) c[a] = b;
        else p[a] = b;
        if (ms[c[a]].empty() || p[a] > *ms[c[a]].begin()) {
            ans += p[a];
            st.insert(p[a]);
            if (!ms[c[a]].empty()) {
                ans -= *ms[c[a]].begin();
                st.extract(*ms[c[a]].begin());
                mx.insert(*ms[c[a]].begin());
            }
            if (ms[c[a]].size() > 1) mx.extract(*(++ms[c[a]].begin()));
        }
        else if (ms[c[a]].size() == 1 || p[a] > *(++ms[c[a]].begin())) {
            if (ms[c[a]].size() > 1) mx.extract(*(++ms[c[a]].begin()));
            mx.insert(p[a]);
        }
        ms[c[a]].insert(p[a]);
        cout << max(ans, ans - *st.begin() + *mx.begin()) << "\n";
    }
    return 0;
}