#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[200001], b[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        sort(b + 1, b + m + 1, greater<int>());
        int j = 1;
        for (int i = 1; i <= m; i++) {
            while (j <= n && a[j] > b[i]) cout << a[j++] << " ";
            cout << b[i] << " ";
        }
        while (j <= n) cout << a[j++] << " ";
        cout << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/