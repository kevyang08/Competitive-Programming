#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int a1 = 0, a2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) a1 += 2;
            if (a[i] != b[n - i - 1]) a2 += 2;
        }
        cout << min(a1 - 1 + (a1/2%2 == 0), max(a2 + (a2/2%2 == 0 ? -1 : 0), 2)) << "\n";
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