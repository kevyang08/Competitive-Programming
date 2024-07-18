#include <bits/stdc++.h>
using namespace std;

int q, n;
string s, t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> q;
    while (q--) {
        cin >> n >> s >> t;
        bool ans = true, one = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') one = true;
            if (s[i] == '0' && t[i] == '1' && !one) ans = false; 
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}