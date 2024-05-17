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
        long long ans = 0, l1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') ans += l1 + (l1 > 0);
            else l1++;
        }
        cout << ans << "\n";
    }
    return 0;
}
