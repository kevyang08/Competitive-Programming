#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        bool ans = false;
        for (int k = 1; k * k <= n; k++) {
            if (k * k != n) continue;
            ans = true;
            for (int i = 0; i < k; i++) if (s[i] != '1') ans = false;
            for (int i = k; i < k * k - k; i++) if ((i%k == 0 || (i + 1)%k == 0) && s[i] != '1' || i%k && (i + 1)%k && s[i] != '0') ans = false;
            for (int i = k * k - k; i < n; i++) if (s[i] != '1') ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}