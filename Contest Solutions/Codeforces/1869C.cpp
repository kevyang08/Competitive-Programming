#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << (m == 1 ? 0 : min(m, n + 1)) << "\n";
        for (int i = 1, k = 1; i <= n; i++, k++) {
            if (k == m) k = 1;
            for (int j = 0; j < m; j++) cout << (j + k)%m << (j == m - 1 ? "\n" : " ");
        }
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

/*
4 3
1 2 0
2 0 1
1 2 0
2 0 1
*/