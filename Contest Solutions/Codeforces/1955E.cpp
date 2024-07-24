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
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> a(n + 2);
            bool thing = true;
            for (int j = 1; j <= n; j++) {
                a[j] += a[j - 1];
                if ((s[j - 1] - '0' + a[j])%2 == 0) {
                    if (j <= n - i + 1) ++a[j], --a[j + i];
                    else thing = false;
                }
            }
            if (thing) ans = i;
        }
        cout << ans << "\n";
    }
    return 0;
}