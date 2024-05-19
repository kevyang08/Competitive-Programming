#include <bits/stdc++.h>
using namespace std;

// time: ~45 mins
// mostly debugging oops

int n, k, a, b, d, ans[200001];
vector<pair<int, int>> adj[200001];
vector<int> s;
int bs(int l, int r, int v) {
    while (l < r) {
        int m = (l + r + 1)/2;
        if (s[m] <= v) l = m;
        else r = m - 1;
    }
    return l;
}
void dfs(int i, int p, int l, int r) {
    ans[i] = max(0, r - l + 1);
    for (auto it = adj[i].begin(); it != adj[i].end(); it++) if (it -> second == p) {
        adj[i].erase(it);
        break;
    }
    sort(adj[i].begin(), adj[i].end());
    vector<int> v;
    v.push_back(-1);
    int lo = l;
    for (int j = 0; j < adj[i].size(); j++) {
        if (j + 1 < adj[i].size()) v.push_back((adj[i][j].first + adj[i][j + 1].first)/2);
        else v.push_back(0x3f3f3f3f);
        int hi = bs(lo - 1, r, v[j + 1]);
        dfs(adj[i][j].second, i, lo, hi);
        if (hi >= lo) lo = hi + 1;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    s.resize(k);
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({d, b});
        adj[b].push_back({d, a});
    }
    for (int i = 0; i < k; i++) cin >> s[i];
    sort(s.begin(), s.end());
    dfs(1, 0, 0, k - 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? "\n" : " ");
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
