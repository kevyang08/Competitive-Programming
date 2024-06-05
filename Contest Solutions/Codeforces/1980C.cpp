#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], b, m, d;
map<int, int> cnt;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cnt.clear();
        cin >> n;
        bool ans = true;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            cin >> b;
            cnt[b] += 1 - (a[i] == b);
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> d;
            if (i == m && cnt.find(d) == cnt.end()) ans = false;
            if (cnt.find(d) != cnt.end()) cnt[d]--;
        }
        for (auto [k, v] : cnt) if (v > 0) ans = false;
        cout << (ans ? "YES\n" : "NO\n");
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
