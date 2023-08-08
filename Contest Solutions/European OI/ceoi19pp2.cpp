#include <bits/stdc++.h>
using namespace std;

int n, a, b, s = 0, mx = -1, MOD = 1e9;
stack<int> st;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        a = (b + s)%MOD;
        if (a > mx) {
            st.push(a);
            mx = a;
        }
        else while(!st.empty() && st.top() >= a) st.pop();
        s = st.size();
        cout << s << "\n";
    }
    return 0;
}
