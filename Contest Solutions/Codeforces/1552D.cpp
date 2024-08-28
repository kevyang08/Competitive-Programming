#include <bits/stdc++.h>
using namespace std;

int t, n, a;
vector<int> v;
void solve() {
    set<int> st;
    st.insert(0);
    for (int i = 0; i < n - 1; i++) {
        if (st.find(v[i]) != st.end()) {
            cout << "YES\n";
            return;
        }
        set<int> temp;
        for (int j : st) temp.insert(j), temp.insert(j - v[i]), temp.insert(j + v[i]);
        st = move(temp);
    }
    cout << (st.find(v[n - 1]) != st.end() ? "YES\n" : "NO\n");
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a;
            v[i] = abs(a);
        }
        sort(v.begin(), v.end());
        solve();
    }
    return 0;
}