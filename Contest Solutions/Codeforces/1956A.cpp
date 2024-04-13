#include <bits/stdc++.h>
using namespace std;

int k, q, a[101], n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> k >> q;
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= q; i++) {
            cin >> n;
            cout << min(n, a[1] - 1) << (i == q ? "\n" : " ");
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
