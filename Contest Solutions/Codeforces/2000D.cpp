#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[200001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        queue<int> q;
        stack<int> st;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') q.push(i + 1);
            else st.push(i + 1);
        }
        while (!q.empty() && !st.empty() && q.front() < st.top()) {
            ans += a[st.top()] - a[q.front() - 1];
            st.pop(); q.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}