#include <bits/stdc++.h>
using namespace std;

int n, in[2][500001], dp[2][500001], ind[500001], ans = 0, nxt[500001];
queue<int> q;
int solve(int i, int m) {
    ind[i] = 0;
    dp[m][i] = in[m][i];
    dp[m ^ 1][i] = 0;
    int l = i;
    for (int j = nxt[i]; j != i; j = nxt[j]) {
        ind[j] = 0;
        dp[0][j] = in[0][j] + max(dp[1][l], dp[0][l]);
        dp[1][j] = in[1][j] + dp[0][l];
        l = j;
    }
    return m ? dp[0][l] : max(dp[0][l], dp[1][l]);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        ind[nxt[i]]++;
        in[1][i] = 1;
    }
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        in[0][nxt[c]] += max(in[0][c], in[1][c]);
        in[1][nxt[c]] += in[0][c];
        ind[nxt[c]]--;
        if (!ind[nxt[c]]) q.push(nxt[c]);
    }
    for (int i = 1; i <= n; i++) if (ind[i]) ans += max(solve(i, 0), solve(i, 1));
    cout << ans << "\n";
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