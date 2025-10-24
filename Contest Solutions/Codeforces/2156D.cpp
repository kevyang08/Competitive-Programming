#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, r;
void solve() {
    cin >> n;
    vector<int> v(n - 1);
    iota(v.begin(), v.end(), 1);
    vector<int> st(v.begin(), v.end());
    st.push_back(n);
    for (int k = 1; st.size() > 1; k <<= 1) {
        vector<int> st1, st2;
        for (int i : st) {
            if (i & k) st1.push_back(i);
            else st2.push_back(i);
        }
        vector<int> v1, v2;
        for (int i : v) {
            cout << "? " << i << " " << k << endl;
            cin >> r;
            if (r) v1.push_back(i);
            else v2.push_back(i);
        }
        if (v1.size() < st1.size()) {
            swap(v, v1);
            swap(st, st1);
        }
        else {
            swap(v, v2);
            swap(st, st2);
        }
    }
    cout << "! " << st[0] << endl;
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