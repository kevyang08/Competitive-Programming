#include <bits/stdc++.h>
using namespace std;
 
int t;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        bool used[s.length()];
        memset(used, true, sizeof(used));
        stack<int> lo, up;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                if (!lo.empty()) {
                    used[lo.top()] = false;
                    lo.pop();
                }
                used[i] = false;
            }
            else if (s[i] == 'B') {
                if (!up.empty()) {
                    used[up.top()] = false;
                    up.pop();
                }
                used[i] = false;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') lo.push(i);
            else up.push(i);
        }
        for (int i = 0; i < s.length(); i++) if (used[i]) cout << s[i];
        cout << "\n";
    }
    return 0;
}
