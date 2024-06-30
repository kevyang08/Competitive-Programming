#include <bits/stdc++.h>
using namespace std;

int t, n, c[200005], k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int idx = 1, r = 0, ans = 0;
        vector<int> v;
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            while (!v.empty() && c[v.back()] >= c[i]) v.pop_back();
            v.push_back(i);
        }
        c[n + 1] = 0x3f3f3f3f;
        v.push_back(n + 1);
        cin >> k;
        if (k >= c[v[0]]) {
            r = k%c[v[0]];
            ans = k/c[v[0]];
            for (int i = 1; i < v.size(); i++) {
                if (k/c[v[i - 1]] > k/c[v[i]]) {
                    int temp = r/(c[v[i]] - c[v[i - 1]]);
                    q.push({v[i - 1], ans});
                    k -= (ans - temp) * c[v[i - 1]];
                    ans = temp;
                }
                if (k < c[v[i]]) break;
                r = k%c[v[i]];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << (q.empty() ? 0 : q.front().second) << (i == n ? "\n" : " ");
            while (!q.empty() && q.front().first == i) q.pop();
        }
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/