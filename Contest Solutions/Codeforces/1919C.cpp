#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[200001], b[200001], x;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    a[0] = b[0] = 0x3f3f3f3f;
    cin >> t;
    while (t--) {
        cin >> n;
        int j = 0, k = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (a[j] >= x && b[k] >= x || a[j] < x && b[k] < x) {
                if (a[j] < b[k]) a[++j] = x;
                else b[++k] = x;
            }
            else if (a[j] >= x) a[++j] = x;
            else b[++k] = x;
        }
        for (int i = 1; i < j; i++) if (a[i] < a[i + 1]) ans++;
        for (int i = 1; i < k; i++) if (b[i] < b[i + 1]) ans++;
        cout << ans << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, think of a new one
- make sure question was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
