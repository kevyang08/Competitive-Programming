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
        cin >> n >> k >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') cnt++;
        }
        if (cnt < k) {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'A') cnt++;
                if (cnt == k) {
                    cout << "1\n" << i + 1 << " B\n";
                    break;
                }
            }
        }
        else if (cnt > k) {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'B') cnt--;
                if (cnt == k) {
                    cout << "1\n" << i + 1 << " A\n";
                    break;
                }
            }
        }
        else cout << 0 << "\n";
    }
    return 0;
}
