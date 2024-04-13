#include <bits/stdc++.h>
using namespace std;

int t;
string x, y;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        int n = x.length(), i = 0;
        while (i < n && x[i] == y[i]) cout << x[i++];
        if (i < n) {
            cout << max(x[i], y[i]);
            ++i;
            for (; i < n; i++) cout << min(x[i], y[i]);
        }
        cout << "\n";
        i = 0;
        while (i < n && x[i] == y[i]) cout << y[i++];
        if (i < n) {
            cout << min(x[i], y[i]);
            ++i;
            for (; i < n; i++) cout << max(x[i], y[i]);
        }
        cout << "\n";
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
