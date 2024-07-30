#include <bits/stdc++.h>
using namespace std;

/*
- max ans can always be n/2 - 1
- each local max can be n + 2
*/

int t, n, p[100001], q[100001], idx[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) idx[p[i]] = i;
        vector<int> v(n);
        iota(v.rbegin(), v.rend(), 1);
        set<int> s(v.begin(), v.end()), st;
        for (int i = 2; i < n; i++) if (i%2 != idx[1]%2) st.insert(p[i]);
        for (int i : st) {
            q[idx[i]] = *s.rbegin();
            s.erase(q[idx[i]]);
        }
        for (int i : v) if (st.find(i) == st.end()) {
            q[idx[i]] = *s.begin();
            s.erase(q[idx[i]]);
        }
        for (int i = 1; i <= n; i++) cout << q[i] << (i == n ? "\n" : " ");
    }
    return 0;
}