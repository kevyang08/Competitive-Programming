#include <bits/stdc++.h>
using namespace std;

string s;
int n = 0, mn[2][500000], mx[2][500000];
void dfs(int i) {
    if (s[i] == '0') mn[1][i] = mx[1][i] = 1;
    else if (s[i] == '1') {
        int c = ++n;
        dfs(c);
        mn[0][i] = min(mn[0][c], mn[1][c]);
        mn[1][i] = 1 + mn[0][c];
        mx[0][i] = max(mx[0][c], mx[1][c]);
        mx[1][i] = 1 + mx[0][c];
    }
    else {
        int c = ++n;
        dfs(c);
        int d = ++n;
        dfs(d);
        mn[0][i] = min(mn[0][c] + mn[1][d], mn[1][c] + mn[0][d]);
        mn[1][i] = 1 + mn[0][c] + mn[0][d];
        mx[0][i] = max(mx[0][c] + mx[1][d], mx[1][c] + mx[0][d]);
        mx[1][i] = 1 + mx[0][c] + mx[0][d];
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> s;
    dfs(0);
    cout << max(mx[0][0], mx[1][0]) << " " << min(mn[0][0], mn[1][0]) << "\n";
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
