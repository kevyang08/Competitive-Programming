#include <bits/stdc++.h>
using namespace std;

int t, p[200001];
long long n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int l = 1, r = n; l <= r; l++) {
            if (k >= 2 * (r - l)) {
                k -= 2 * (r - l);
                p[l] = r, p[r--] = l;
            }
            else p[l] = l, p[r] = r;
        }
        // if (k == 2) {
        //     for (int i = 1; i < n/2 + n%2; i++) if (p[i] == i) {
        //         swap(p[i], p[i + 1]);
        //         break;
        //     }
        //     k = 0;
        // }
        if (k) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? "\n" : " ");
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
1
6 14

YES
6 3 2 5 4 1
*/