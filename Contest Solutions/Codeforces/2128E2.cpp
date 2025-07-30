#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, a[300005], aidx[600005], off = 300000;
set<int> st;
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
    auto print_med = [&](int lo, int hi) {
        if (st.find(pql.top()) != st.end()) {
            cout << pql.top() << " " << lo << " " << hi << "\n";
            st.erase(pql.top());
        }
        if (pql.size() == pqr.size()) {
            while (st.upper_bound(pql.top()) != st.end() && *st.upper_bound(pql.top()) <= -pqr.top()) {
                cout << *st.upper_bound(pql.top()) << " " << lo << " " << hi << "\n";
                st.erase(st.upper_bound(pql.top()));
            }
        }
    };
    print_med(l, r);
    for (int i = r + 1; i <= n; i++) {
        enq(a[i]);
        print_med(l, i);
    }
    for (int i = l - 1; i > 0; i--) {
        enq(a[i]);
        print_med(i, n);
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
    int l = v[v.size()/2], r = n, mxl = 1, mxr = n, mnl = 1, mnr = n, lo, hi;
    while (l < r) {
        int m = (l + r + 1)/2;
        auto [rl, rr] = get_mx_idx(m);
        if (rl == -1) r = m - 1;
        else {
            l = m;
            mxl = rl, mxr = rr;
        }
    }
    hi = l, l = 1, r = v[v.size()/2];
    while (l < r) {
        int m = (l + r)/2;
        auto [rl, rr] = get_mn_idx(m);
        if (rl == -1) l = m + 1;
        else {
            r = m;
            mnl = rl, mnr = rr;
        }
    }
    lo = r;
    cout << hi - lo + 1 << "\n";
    for (int i = lo; i <= hi; i++) st.insert(i);
    get_med(mxl, mxr);
    get_med(mnl, mnr);
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