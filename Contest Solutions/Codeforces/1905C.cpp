#include <bits/stdc++.h>
using namespace std;
 
int t, n;
string s;
char res[200000];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        stack<char> st;
        deque<int> dq;
        bool thing = true;
        int ans = 0;
        char mx = 'a';
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() < s[i]) {
                st.pop();
                dq.pop_back();
            }
            st.push(s[i]);
            dq.push_back(i);
            mx = max(s[i], mx);
        }
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() == i) {
                dq.pop_front();
                res[i] = st.top();
                st.pop();
                if (res[i] != mx) ans++;
            }
            else res[i] = s[i];
            if (i > 0 && res[i - 1] > res[i]) thing = false;
        }
        cout << (thing ? ans : -1) << "\n";
    }
    return 0;
}
