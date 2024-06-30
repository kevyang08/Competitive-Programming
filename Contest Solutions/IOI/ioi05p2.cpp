#include <bits/stdc++.h>
using namespace std;

int n;
long long m, pr = 0x3f3f3f3f3f3f3f3f, pl = -pr;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        long long temp = min(pr, m);
        if (pr < pl) break;
        pr = m + m - pl;
        pl = m + m - temp;
    }
    cout << max(pr - pl + 1, 0LL) << "\n";
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