#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> adj[100001];
set<int> st[100001];
long long ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) st[i].insert(j);
        ans += st[i].size();
        int temp = *st[i].begin();
        st[i].erase(temp);
        if (st[temp].size() < st[i].size()) swap(st[temp], st[i]);
        for (int j : st[i]) st[temp].insert(j);
    }
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
