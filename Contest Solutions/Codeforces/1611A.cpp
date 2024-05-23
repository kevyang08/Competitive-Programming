#include <bits/stdc++.h>
using namespace std;

int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n%2 == 0) {
            cout << "0\n";
            continue;
        }
        int i = -1, j = 0;
        while (n) {
            if (n%2 == 0) i = j;
            j++;
            n /= 10;
        }
        cout << (i == -1 ? -1 : i == j - 1 ? 1 : 2) << "\n";
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
