#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, a[300005], aidx[600005], off = 300000;
multiset<pair<int, int>> st;
queue<pair<int, int>> ql[300005], qr[300005];
void get_med(int l, int r) {
    priority_queue<int> pql, pqr;
    auto enq = [&](auto x) {
        if (pql.empty() || x < pql.top()) {
            pql.push(x);
            if (pql.size() - pqr.size() > 1) {
                pqr.push(-pql.top());
                pql.pop();
            }
        }
        else {
            pqr.push(-x);
            if (pqr.size() > pql.size()) {
                pql.push(-pqr.top());
                pqr.pop();
            }
        }
    };
    for (int i = l; i <= r; i++) enq(a[i]);
    ql[pql.top()].push({l, r});
    if (pql.size() > pqr.size()) qr[pql.top()].push({l, r});
    else qr[-pqr.top()].push({l, r});
    for (int i = r + 1; i <= n; i++) {
        enq(a[i]);
        ql[pql.top()].push({l, i});
        if (pql.size() > pqr.size()) qr[pql.top()].push({l, i});
        else qr[-pqr.top()].push({l, i});
    }
    for (int i = l - 1; i > 0; i--) {
        enq(a[i]);
        ql[pql.top()].push({i, n});
        if (pql.size() > pqr.size()) qr[pql.top()].push({i, n});
        else qr[-pqr.top()].push({i, n});
    }
}
pair<int, int> get_mx_idx(int m) {
    int sm = 0, smk = 0, rl = -1, rr = n;
    for (int i = 1; i <= n; i++) {
        smk += (a[i] >= m ? 1 : -1);
        if (i < k) continue;
        aidx[sm + off] = i - k + 1;
        if (aidx[smk + off]) {
            rl = aidx[smk + off], rr = i;
            break;
        }
        sm += (a[i - k + 1] >= m ? 1 : -1);
    }
    sm = 0;
    for (int i = 1; i <= rr - k + 1; i++) {
        aidx[sm + off] = 0;
        sm += (a[i] >= m ? 1 : -1);
    }
    return {rl, rr};
}
pair<int, int> get_mn_idx(int m) {
    int sm = 0, smk = 0, rl = -1, rr = n;
    for (int i = 1; i <= n; i++) {
        smk += (a[i] > m ? 1 : -1);
        if (i < k) continue;
        aidx[sm + off] = i - k + 1;
        if (aidx[smk + off]) {
            rl = aidx[smk + off], rr = i;
            break;
        }
        sm += (a[i - k + 1] > m ? 1 : -1);
    }
    sm = 0;
    for (int i = 1; i <= rr - k + 1; i++) {
        aidx[sm + off] = 0;
        sm += (a[i] > m ? 1 : -1);
    }
    return {rl, rr};
}
void solve() {
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int l = v[v.size()/2], r = n, mxl = 1, mxr = n, mnl = 1, mnr = n;
    while (l < r) {
        int m = (l + r + 1)/2;
        auto [rl, rr] = get_mx_idx(m);
        if (rl == -1) r = m - 1;
        else {
            l = m;
            mxl = rl, mxr = rr;
        }
    }
    l = 1, r = v[v.size()/2];
    while (l < r) {
        int m = (l + r)/2;
        auto [rl, rr] = get_mn_idx(m);
        if (rl == -1) l = m + 1;
        else {
            r = m;
            mnl = rl, mnr = rr;
        }
    }
    get_med(mxl, mxr);
    get_med(mnl, mnr);
    vector<tuple<int, int, int>> va;
    for (int i = 1; i <= n; i++) {
        while (!ql[i].empty()) {
            st.insert(ql[i].front());
            ql[i].pop();
        }
        if (!st.empty()) va.push_back({i, st.begin() -> fi, st.begin() -> se});
        while (!qr[i].empty()) {
            st.extract(qr[i].front());
            qr[i].pop();
        }
    }
    cout << va.size() << "\n";
    for (auto &[a, b, c] : va) cout << a << " " << b << " " << c << "\n";
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