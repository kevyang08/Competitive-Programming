#include <bits/stdc++.h>
using namespace std;

/*
- 0 operations: algorithm ends at x
- 1 operation: end number is swappable with x without changing the rest of the sequence
    - if x is in the sequence, end must be < x
    - else yes
- 2 operations
    - if <= 1 is not possible, a number <= x not in the seq has to exist
    - else change direction (or try just changing right away)
*/

int t, n, x, p[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        set<int> st;
        cin >> n >> x;
        int l = 1, r = n + 1, idx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            if (p[i] == x) idx = i;
        }
        while (r - l > 1) {
            int m = (l + r)/2;
            st.insert(p[m]);
            if (p[m] <= x) l = m;
            else r = m;
        }
        if (p[l] == x) cout << "0\n";
        else if (st.find(x) == st.end() || p[l] < x) cout << "1\n" << l << " " << idx << "\n";
        else {
            swap(p[l], p[idx]);
            idx = l, l = 1, r = n + 1;
            while (r - l > 1) {
                int m = (l + r)/2;
                if (p[m] <= x) l = m;
                else r = m;
            }
            cout << "1\n" << l << " " << idx << "\n";
        }
    }
    return 0;
}