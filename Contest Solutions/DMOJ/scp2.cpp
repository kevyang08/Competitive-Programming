#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    int cntl = 0, cntr = 0, l = 1, r = n;
    while (l <= n && s[l - 1] == s[0]) {
        cntl++;
        l++;
    }
    while (r >= l && s[r - 1] == s[0]) {
        cntr++;
        r--;
    }
    int cnt = cntl + cntr;
    if (l > n) cout << 1 << "\n";
    else if (cntl && cntr) {
        int c = 1, thing = cnt - 1;
        for (int i = l - 1; i < r; i++) {
            if (i > 0 && s[i] == s[i - 1]) c++;
            else {
                thing += c - 1;
                c = 1;
            }
        }
        thing += c - 1;
        int ans = n - thing;
        cout << ans << "\n";
    }
    else cout << n << "\n";
    return 0;
}
