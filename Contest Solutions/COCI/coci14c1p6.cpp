#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, a, b, c, cnt[500001];
ll mx[500001], tot[500001], ans[500001];
vector<pair<int, int>> adj[500001];
bool team[500001];
bool dfs(int i, int p) {
    for (auto &j : adj[i]) {
        if (j.first == p) continue;
        bool res = dfs(j.first, i);
        if (res) {
            cnt[i]++;
            mx[i] = max(mx[i], mx[j.first] + j.second);
            tot[i] += tot[j.first] + j.second;
        }
    }
    return cnt[i] || team[i];
}
void dp(int i, int p, ll t, ll m, bool thing) {
    mx[i] = max(mx[i], m);
    ans[i] = ((tot[i] + t) << 1) - mx[i];
    ll mxtemp = m;
    bool bruh = false;
    for (auto &j : adj[i]) {
        if (j.first == p || !(cnt[j.first] || team[j.first])) continue;
        if (mx[j.first] + j.second == mx[i] && !bruh) {
            bruh = true;
            continue;
        }
        mxtemp = max(mxtemp, mx[j.first] + j.second);
    }
    t += tot[i];
    if (cnt[i] > 1 || team[i]) thing = true;
    for (auto &j : adj[i]) {
        if (j.first == p) continue;
        if (thing) {
            if ((cnt[j.first] || team[j.first]) && mx[j.first] + j.second == mx[i]) dp(j.first, i, (cnt[j.first] || team[j.first] ? t - tot[j.first] : t + j.second), mxtemp + j.second, true);
            else dp(j.first, i, (cnt[j.first] || team[j.first] ? t - tot[j.first] : t + j.second), max(mxtemp, mx[i]) + j.second, true);
        }
        else dp(j.first, i, 0, 0, false);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    while (k--) {
        cin >> a;
        team[a] = true;
    }
    dfs(a, 0);
    dp(a, 0, 0, 0, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}
