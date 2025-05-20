#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// bruh
// remember to make temp variables

vector<int> st, w, id, mne, mno, ex;
int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
}
void join(int u, int v) {
    mno[u] = min(mno[u], (id[u] & 1 ? mne[v] : mno[v]));
    mne[u] = min(mne[u], (id[u] & 1 ? mno[v] : mne[v]));
    id[u] += id[v];
    id[v] = u;
}
vector<ll> calculate_costs(vector<int> W, vector<int> A, vector<int> B, vector<int> E) {
    int n = W.size(), q = E.size();
    ll cur = 0;
    vector<ll> ans(q);
    vector<pair<int, int>> v, ed, vq;
    for (int i = 0; i < q; i++) vq.push_back({E[i], i});
    sort(vq.begin(), vq.end());
    for (int i = 0; i < n; i++) cur += B[i], v.push_back({W[i], A[i] - B[i]});
    sort(v.begin(), v.end());
    st.resize(n);
    w.resize(n);
    id.resize(n, -1);
    mne.resize(n, INF);
    mno.resize(n);
    ex.resize(n);
    for (int i = 0; i < n; i++) {
        w[i] = v[i].fi;
        st[i] = i;
        mno[i] = ex[i] = v[i].se;
        cur += mno[i];
        if (i > 0) ed.push_back({i - 1, i});
        if (i > 1) ed.push_back({i - 2, i});
    }
    sort(ed.begin(), ed.end(), [&](auto a, auto b) {
        if (w[a.se] - w[a.fi] != w[b.se] - w[b.fi]) return w[a.se] - w[a.fi] > w[b.se] - w[b.fi];
        return a.se - a.fi != b.se - b.fi ? a.se - a.fi > b.se - b.fi : a.se > b.se;
    });
    for (auto &[d, idx] : vq) {
        while (!ed.empty() && w[ed.back().se] - w[ed.back().fi] <= d) {
            auto [u, v] = ed.back(); ed.pop_back();
            if (find(u) != find(v)) {
                u = find(u), v = find(v);
                if (id[u] & 1) cur -= mno[u];
                if (id[v] & 1) cur -= mno[v];
                join(u, v);
                u = find(u);
                if (id[u] & 1) cur += mno[u];
            }
            else {
                int m = u + 1, a = find(u);
                if (m%2 != st[a]%2) {
                    if (mno[a] > ex[m] && (id[a] & 1)) cur += ex[m] - mno[a];
                    mno[a] = min(mno[a], ex[m]);
                }
                else mne[a] = min(mne[a], ex[m]);
            }
        }
        ans[idx] = cur;
    }
    return ans;
}