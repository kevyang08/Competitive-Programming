#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001], x, y;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        a[1] = x;
        if (y - n * (n - 1)/2 < x) cout << "-1\n";
        else for (int i = 1, j = n - 1; i <= n; i++, j--) cout << (i == 1 ? a[i] = x : y - j * (j + 1)/2) << (i == n ? "\n" : " ");
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