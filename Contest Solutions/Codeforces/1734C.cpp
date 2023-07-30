#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long long ans = 0;
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool used[n]{0};
        for (int i = 1; i <= s.size(); i++) {
            if (used[i - 1] || s[i - 1] == '0') {
                for (int j = i - 1; j < s.size(); j += i) {
                    if (!used[j] && s[j] != '0') break;
                    if (!used[j]) ans += i;
                    s[j] = '1';
                    used[j] = true;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
