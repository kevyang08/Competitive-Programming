#include <bits/stdc++.h>
using namespace std;

int t, n;
long long arr[2001][2001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (long long i = 1; i <= 2000; i++) for (int j = 1; j <= i; j++) arr[i][j] = arr[i - 1][j] + pow(i * (i - 1)/2 + j, 2);
    cin >> t;
    while (t--) {
        cin >> n;
        int r, c;
        long long ans = 0;
        for (int i = 0; i < 2000; i++) if (i * (i + 1)/2 < n) r = i + 1, c = n - i * (i + 1)/2;
        for (int i = c; i > 0; i--) ans += arr[r--][i];
        cout << ans << "\n";
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