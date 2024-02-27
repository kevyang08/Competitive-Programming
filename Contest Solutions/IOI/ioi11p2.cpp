// small-to-large merging with more fun stuff
// unordered_map is somehow slower, even though theoretically should be faster than map

#include <bits/stdc++.h>
using namespace std;

int ans = 0x3f3f3f3f, offc[200000];
int off[200000];
vector<pair<int, int>> adj[200000];
map<int, int> mp[200000];
void dfs(int i, int p, int k) {
    for (auto j : adj[i]) {
        if (j.first == p) continue;
        dfs(j.first, i, k);
        off[j.first] += j.second;
        offc[j.first]++;
        if (mp[j.first].size() > mp[i].size()) {
            swap(mp[i], mp[j.first]);
            swap(off[i], off[j.first]);
            swap(offc[i], offc[j.first]);
        }
        for (auto e : mp[j.first]) {
            if (e.first + off[j.first] > k) continue;
            if (mp[i].find(k - e.first - off[j.first] - off[i]) != mp[i].end()) {
                ans = min(ans, e.second + mp[i][k - e.first - off[j.first] - off[i]] + offc[i] + offc[j.first]);
            }
        }
        off[j.first] -= off[i];
        offc[j.first] -= offc[i];
        for (auto e : mp[j.first]) {
            if (e.first + off[j.first] + off[i] > k) continue;
            if (mp[i].find(e.first + off[j.first]) == mp[i].end() || mp[i][e.first + off[j.first]] > e.second + offc[j.first]) {
                mp[i][e.first + off[j.first]] = e.second + offc[j.first];
            }
        }
    }
    if (mp[i].find(k - off[i]) != mp[i].end()) ans = min(ans, mp[i][k - off[i]] + offc[i]);
    mp[i][-off[i]] = -offc[i];
}
int best_path(int N, int K, int H[][2], int L[]) {
    for (int i = 0; i < N - 1; i++) {
        adj[H[i][0]].push_back({H[i][1], L[i]});
        adj[H[i][1]].push_back({H[i][0], L[i]});
    }
    dfs(0, N, K);
    return (ans == 0x3f3f3f3f ? -1 : ans);
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
