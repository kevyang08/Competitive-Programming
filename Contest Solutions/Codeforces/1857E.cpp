#include <bits/stdc++.h>
using namespace std;

int t, n, idx[200001];
long long x[200001], ans[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long l = n, r = 0;
        for (int i = 1; i <= n; i++) idx[i] = i;
        for (int i = 1; i <= n; i++) cin >> x[i];
        sort(idx + 1, idx + n + 1, [&](auto a, auto b) {return x[a] < x[b];});
        sort(x + 1, x + n + 1);
        for (int i = 2; i <= n; i++) if (x[i] > x[i - 1]) r += (x[i] - x[i - 1]) * (n - i + 1);
        for (int i = 1; i <= n; i++) {
            ans[idx[i]] = l + r;
            if (i == n || x[i + 1] == x[i]) continue;
            r -= (x[i + 1] - x[i]) * (n - i);
            l += (x[i + 1] - x[i]) * i;
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? "\n" : " ");
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
