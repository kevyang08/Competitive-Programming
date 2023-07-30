#include <bits/stdc++.h>
using namespace std;
 
int n, l = 0, mx = 0;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') l++;
        else {
            mx = max(mx, l);
            l = 0;
        }
    }
    if (l != 0 && l != n) mx = max(mx, l);
    cout << (mx ? mx : -1) << "\n";
    return 0;
}
