#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, x, y, k, dp[1000001], ck = 1;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fill(dp, dp + 1000001, INF);
    dp[1] = 0;
    cin >> t;
    vector<array<int, 4>> vq;
    vector<int> ans(t);
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> k;
        vq.push_back({k, x, y, i});
    }
    sort(vq.begin(), vq.end());
    for (auto &[k, x, y, i] : vq) {
        while (ck < k) {
            ++ck;
            for (int j = ck; j <= 1000000; j += ck) dp[j] = min(dp[j], dp[j/ck] + 1);
        }
        int g = __gcd(x, y);
        if (dp[x/g] == INF || dp[y/g] == INF) {
            ans[i] = -1;
            continue;
        }
        ans[i] = dp[x/g] + dp[y/g];
    }
    for (int i = 0; i < t; i++) cout << ans[i] << "\n";
    return 0;
}