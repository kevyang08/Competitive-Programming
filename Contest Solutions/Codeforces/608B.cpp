#include <bits/stdc++.h>
using namespace std;

string a, b;
long long ans = 0;
int cnt[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> a >> b;
    int n = a.length(), m = b.length();
    for (int i = 1; i <= m; i++) cnt[i] = cnt[i - 1] + (b[i - 1] - '0');
    for (int i = 0; i < n; i++) ans += abs((int)(a[i] - '0') * (m - n + 1) - (cnt[m - n + i + 1] - cnt[i]));
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
