// small-to-large merging with more fun stuff
// unordered_map is somehow slower, even though theoretically should be faster than map

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, u, v, l, ans = 0x3f3f3f3f, offc[200000];
ll off[200000];
vector<pair<int, int>> adj[200000];
map<ll, int> mp[200000];
void dfs(int i, int p) {
    for (auto j : adj[i]) {
        if (j.first == p) continue;
        dfs(j.first, i);
        off[j.first] += j.second;
        offc[j.first]++;
        if (mp[j.first].size() > mp[i].size()) {
            swap(mp[i], mp[j.first]);
            swap(off[i], off[j.first]);
            swap(offc[i], offc[j.first]);
        }
        for (auto e : mp[j.first]) {
            if (mp[i].find(k - e.first - off[j.first] - off[i]) != mp[i].end()) {
                ans = min(ans, e.second + mp[i][k - e.first - off[j.first] - off[i]] + offc[i] + offc[j.first]);
            }
        }
        off[j.first] -= off[i];
        offc[j.first] -= offc[i];
        for (auto e : mp[j.first]) {
            if (mp[i].find(e.first + off[j.first]) == mp[i].end() || mp[i][e.first + off[j.first]] > e.second + offc[j.first]) {
                mp[i][e.first + off[j.first]] = e.second + offc[j.first];
            }
        }
    }
    if (mp[i].find(k - off[i]) != mp[i].end()) ans = min(ans, mp[i][k - off[i]] + offc[i]);
    mp[i][-off[i]] = -offc[i];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    dfs(0, n);
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
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
