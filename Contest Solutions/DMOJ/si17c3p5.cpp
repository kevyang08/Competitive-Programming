#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// r += 1, b -= 1

int n, a, b, off[100001];
char c;
ll ans = 0;
vector<pair<int, int>> adj[100001];
map<int, ll> mp[100001];
void dfs(int i, int p) {
    for (auto &[j, dt] : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        off[j] += dt;
        ++mp[j][dt - off[j]];
        if (mp[i].size() < mp[j].size()) {
            swap(off[i], off[j]);
            swap(mp[i], mp[j]);
        }
        for (auto [k, v] : mp[j]) {
            if (mp[i].find(-(k + off[j]) - off[i] + 1) != mp[i].end()) ans += mp[i][-(k + off[j]) - off[i] + 1] * v;
            if (mp[i].find(-(k + off[j]) - off[i] - 1) != mp[i].end()) ans += mp[i][-(k + off[j]) - off[i] - 1] * v;
        }
        for (auto [k, v] : mp[j]) mp[i][k + off[j] - off[i]] += v;
    }
    ans += mp[i][-off[i] - 1] + mp[i][-off[i] + 1] - adj[i].size() + (p != 0);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, (c == 'r' ? 1 : -1)});
        adj[b].push_back({a, (c == 'r' ? 1 : -1)});
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}