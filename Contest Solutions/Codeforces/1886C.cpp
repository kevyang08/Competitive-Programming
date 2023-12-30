#include <bits/stdc++.h>
using namespace std;

int t;
long long p;
string s;
stack<int> st;
queue<int> q;
bool thing[1000000];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s >> p;
        for (int i = 0; i < s.length(); i++) {
            thing[i] = false;
            while (!st.empty() && s[st.top()] > s[i]) {
                q.push(st.top());
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        for (int i = s.length(); i > 0; i--) {
            if (p <= i) break;
            p -= i;
            thing[q.front()] = true;
            q.pop();
        }
        for (int j = 0, k = 0; j < s.length(); j++) {
            if (thing[j]) continue;
            if (++k == p) {
                cout << s[j];
                break;
            }
        }
        while (!q.empty()) q.pop();
    }
    return 0;
}
