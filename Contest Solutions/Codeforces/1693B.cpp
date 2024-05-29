#include <bits/stdc++.h>
using namespace std;

int t, n, p, l[200001], r[200001], ans;
vector<int> adj[200001];
long long dfs(int i) {
    long long res = 0;
    for (int j : adj[i]) res += dfs(j);
    if (res < l[i]) {
        ans++;
        return r[i];
    }
    return min(static_cast<long long>(r[i]), res);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 2; i <= n; i++) {
            cin >> p;
            adj[p].push_back(i);
        }
        for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
        dfs(1);
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
