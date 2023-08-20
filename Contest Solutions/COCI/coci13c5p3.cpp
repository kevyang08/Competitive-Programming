#include <bits/stdc++.h>
using namespace std;

string s, t;
int j = 0;
stack<pair<int, int>> st;
bool ans[1000000], bruh = true;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[j]) j = 0;
        if (s[i] == t[j]) st.push({i, j++});
        else while (!st.empty()) st.pop();
        if (j == t.length()) {
            while (j--) {
                ans[st.top().first] = true;
                st.pop();
            }
            if (!st.empty()) j = st.top().second + 1;
            else j = 0;
        } 
    }
    for (int i = 0; i < s.length(); i++) if (!ans[i]) {
        cout << s[i];
        bruh = false;
    }
    if (bruh) cout << "FRULA";
    cout << "\n";
    return 0;
}
