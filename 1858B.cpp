#include <bits/stdc++.h>
using namespace std;

int t, n, m, d, s[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    s[0] = 1;
    while (t--) {
        cin >> n >> m >> d;
        int ans = m + 1, cnt = 0, p = n + 1;
        for (int i = 1; i <= m; i++) {
            cin >> s[i];
            ans += (s[i] - s[i - 1] - 1)/d;
        }
        if (s[1] == 1) ans--;
        ans += (n - s[m])/d;
        for (int i = m; i > 0; i--) {
            if (s[i] == 1) continue;
            if ((p - s[i - 1] - 1)/d < (p - s[i] - 1)/d + (s[i] - s[i - 1] - 1)/d + 1) cnt++;
            p = s[i];
        }
        if (!cnt) cout << ans << " " << m << "\n";
        else cout << ans - 1 << " " << cnt << "\n";
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
