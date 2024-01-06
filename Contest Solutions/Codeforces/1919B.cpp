#include <bits/stdc++.h>
using namespace std;
 
int t, n;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) ans += (s[i] == '+' ? 1 : -1);
        cout << abs(ans) << "\n";
    }
    return 0;
}
