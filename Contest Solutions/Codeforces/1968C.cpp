#include <bits/stdc++.h>
using namespace std;

int t, n, x[505], a[505];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    a[1] = (int)1e8;
    while (t--) {
        cin >> n;
        for (int i = 2; i <= n; i++) cin >> x[i];
        cout << a[1] << " ";
        for (int i = 2; i <= n; i++) {
            cout << a[i - 1] + x[i] << (i == n ? "\n" : " ");
            a[i] = a[i - 1] + x[i];
        }
    }
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
