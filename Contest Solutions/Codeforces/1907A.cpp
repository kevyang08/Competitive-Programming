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
        for (int i = 1; i <= 8; i++) {
            if (i == s[1] - '0') continue;
            cout << s[0] << i << "\n";
        }
        for (int i = 0; i < 8; i++) {
            if (i == s[0] - 'a') continue;
            cout << (char)(i + 'a') << s[1] << "\n";
        }
    }
    return 0;
}
