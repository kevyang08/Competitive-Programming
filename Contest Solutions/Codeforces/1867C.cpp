#include <bits/stdc++.h>
using namespace std;

int t, n, s, y;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int m = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == m) m++;
        }
        cout << m << endl;
        while (true) {
            cin >> y;
            if (y == -1 || y == -2) break;
            cout << y << endl;
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
0 1 3 4 6

5

>>> 4

4

>>> 3

3

>>> 1

2

>>> 0

1
*/