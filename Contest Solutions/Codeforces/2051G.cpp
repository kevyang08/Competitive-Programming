#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
post-submission: nvm tsp is the slow part
*/

int n, q, s, dp[20][1 << 20], mx[20], adj[20][20], ans = INF;
vector<pair<int, char>> v[20];
char op;
int tsp(int mask, int i) {
    if (__builtin_popcount(mask) == n) dp[i][mask] = mx[i];
    if (dp[i][mask] != INF) return dp[i][mask];
    for (int j = 0; j < n; j++) {
        if (j == i || (mask & (1 << j))) continue;
        dp[i][mask] = min(dp[i][mask], adj[i][j] + tsp(mask | (1 << j), j));
    }
    return dp[i][mask];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    memset(dp, INF, sizeof(dp));
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> s >> op;
        --s;
        v[s].push_back({i, op});
        if (op == '+') ++mx[s];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int r = 1, l = 2, d = 1, pi = 0, pj = 0;
            while (pi < v[i].size() || pj < v[j].size()) {
                if (pi < v[i].size() && (pj == v[j].size() || v[i][pi].first < v[j][pj].first)) {
                    if (v[i][pi].second == '+') ++r;
                    ++pi;
                    if (r >= l) ++l, ++d;
                }
                else {
                    if (v[j][pj].second == '-') ++l;
                    ++pj;
                }
            }
            adj[i][j] = d;
        }
    }
    for (int i = 0; i < n; i++) ans = min(ans, tsp((1 << i), i));
    cout << ans + 1 << "\n";
    return 0;
}