#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<pair<int, int>> v;
set<int> st;
void query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cin >> m;
    if (m == l) {
        st.insert(r);
        v.push_back({l, r});
        return;
    }
    if (st.find(m) == st.end()) query(l, m);
    if (st.find(r) == st.end()) query(m, r);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 2; i <= n; i++) {
            if (st.find(i) != st.end()) continue;
            query(1, i);
        }
        cout << "!";
        for (auto &[a, b] : v) cout << " " << a << " " << b;
        cout << endl;
        st.clear();
        v.clear();
    }
    return 0;
}