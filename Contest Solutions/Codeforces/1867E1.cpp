#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int res = 0, x;
        cin >> n >> k;
        for (int i = 1; i + k - 1 <= n; i += k) {
            cout << "? " << i << endl;
            cin >> x;
            res ^= x;
        }
        if (n%k) {
            cout << "? " << n/k * k - k + n%k/2 + 1 << endl;
            cin >> x;
            res ^= x;
            cout << "? " << n/k * k - k + n%k + 1 << endl;
            cin >> x;
            res ^= x;
        }
        cout << "! " << res << endl;
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
8 6

1 2 3 4 5 6 7 8
? 1
7

6 5 4 3 2 1 7 8
? 2
6

6 7 1 2 3 4 5 8
? 3
9
*/