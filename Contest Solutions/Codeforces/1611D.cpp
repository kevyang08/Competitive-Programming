#include <bits/stdc++.h>
using namespace std;

// first two submissions should not be passing

int t, n, b[200001], p[200001], ans[200001], dist[200001];
set<int> s;
vector<int> adj[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) cin >> p[i];
        if (b[p[1]] != p[1]) cout << "-1\n";
        else {
            bool thing = true;
            s.clear();
            for (int i = 1; i <= n; i++) adj[i].clear();
            int mx = 0;
            ans[p[1]] = 0;
            dist[p[1]] = 0;
            for (int i = 1; i <= n; i++) if (b[i] != i) adj[b[i]].push_back(i);
            for (int j : adj[p[1]]) s.insert(j);
            for (int i = 2; i <= n; i++) {
                if (s.find(p[i]) != s.end()) {
                    s.erase(p[i]);
                    ans[p[i]] = mx - dist[b[p[i]]] + 1;
                    dist[p[i]] = ++mx;
                    for (int j : adj[p[i]]) s.insert(j);
                    // cout << p[i] << " " << b[p[i]] << " " << ans[p[i]] << " " << mx << " bruh\n";
                }
                else {
                    thing = false;
                    break;
                }
            }
            if (thing) for (int i = 1; i <= n; i++) cout << ans[i] << (i == n ? "\n" : " ");
            else cout << "-1\n";
        }
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
