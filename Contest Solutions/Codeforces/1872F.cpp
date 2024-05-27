#include <bits/stdc++.h>
using namespace std;

int t, n, a[100001], c[100001], out[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        queue<int> q, ans;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            out[a[i]]++;
        }
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) if (!out[i]) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ans.push(cur);
            out[a[cur]]--;
            if (!out[a[cur]]) q.push(a[cur]);
        }
        for (int i = 1; i <= n; i++) {
            if (!out[i]) continue;
            int mn = i, cur = a[i];
            while (cur != i) {
                if (c[cur] < c[mn]) mn = cur;
                cur = a[cur];
            }
            cur = a[mn];
            while (out[cur]) {
                ans.push(cur);
                out[cur]--;
                cur = a[cur];
            }
        }
        while (!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << "\n";
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
