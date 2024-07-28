#include <bits/stdc++.h>
using namespace std;

int t, n, k;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 1; j <= n; j++) if (i%k == 0 && j%k == 0) cout << s[j - 1];
            if (i%k == 0) cout << "\n";
        }
    }
    return 0;
}