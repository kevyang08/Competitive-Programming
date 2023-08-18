#include <bits/stdc++.h>
using namespace std;
 
int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.length() == 2 && s == "()") cout << "NO\n";
        else {
            cout << "YES\n";
            bool bruh = false;
            int lo = 0, lc = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ')') {
                    bruh = true;
                    lc++;
                }
                else {
                    if (bruh) {
                        lo = lc = -1;
                        break;
                    }
                    lo++;
                }
            }
            if (lo && lo == lc) lo++;
            for (int i = 0; i < max(lo, lc); i++) cout << "()";
            for (int i = 0; i < s.length() - max(lo, lc); i++) cout << "(";
            for (int i = 0; i < s.length() - max(lo, lc); i++) cout << ")";
            cout << "\n";
        }
    }
    return 0;
}
