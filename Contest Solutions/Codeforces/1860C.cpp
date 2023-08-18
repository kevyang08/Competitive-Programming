#include <bits/stdc++.h>
using namespace std;
 
int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, p, ans = 0, mn = 0x3f3f3f3f;
        stack<int> st;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p;
            while (!st.empty() && st.top() > p) {
                if (st.size() == 2) mn = min(mn, st.top());
                st.pop();
            }
            if (st.size() == 1 && mn > p) ans++;
            st.push(p);
        }
        cout << ans << "\n";
    }
    return 0;
}
