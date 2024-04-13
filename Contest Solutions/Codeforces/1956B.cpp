#include <bits/stdc++.h>
using namespace std;

int n, a[200001], cnt[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            if (cnt[a[i]] == 2) ans++;
        }
        for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
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
