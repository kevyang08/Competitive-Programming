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
        long long ans = 0;
        int c0 = 0, c1 = 0, l0 = 1, l1 = 1, l = 0, r = s.length() - 1;
        for (int i = 0; i <= r; i++) {
            if (s[i] == '1') ++c1;
            else ++c0;
        }
        while (l < s.length() && s[l] == '0') ++l, --c0;
        while (l < s.length() - 1 && s[l + 1] == '1') ++l, ++l1;
        while (r && s[r] == '1') --r, --c1;
        while (r > 1 && s[r - 1] == '0') --r, ++l0;
        while (r > l) {
            if (c0 > c1 || c0 == c1 && l1 > l0) {
                ans += (1e12 + 1) * l1;
                c1 -= l1;
                l1 = 0;
                while (s[l + 1] == '0') ++l, --c0;
                while (s[l + 1] == '1') ++l, ++l1;
            }
            else {
                if (c1 == 1) {
                    ans += 1e12;
                    break;
                }
                ans += (1e12 + 1) * l0;
                c0 -= l0;
                l0 = 0;
                while (s[r - 1] == '1') --r, --c1;
                while (s[r - 1] == '0') --r, ++l0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}