#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, a[5001];
void solve() {
    cin >> n;
    int ans = 1;
    vector<map<int, int>> dp(5001);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[0][a[i]] = 0;
    }
    for (int i = 1; i <= n; i++) {
        priority_queue<int> pq1, pq2;
        pq1.push(a[i]);
        if (dp[i - 1].find(a[i]) != dp[i - 1].end()) dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][a[i]] + 1);
        for (int j = i + 2; j <= n; j += 2) {
            if (a[j - 1] < pq1.top()) {
                pq2.push(-pq1.top());
                pq1.pop();
                pq1.push(a[j - 1]);
            }
            else pq2.push(-a[j - 1]);
            if (a[j] <= -pq2.top()) pq1.push(a[j]);
            else {
                pq1.push(-pq2.top());
                pq2.pop();
                pq2.push(-a[j]);
            }
            int tmp = pq1.top();
            assert(pq1.size() == pq2.size() + 1);
            if (dp[i - 1].find(tmp) != dp[i - 1].end()) dp[j][tmp] = max(dp[j][tmp], dp[i - 1][tmp] + 1);
        }
    }
    for (auto &[a, b] : dp[n]) ans = max(ans, b);
    cout << ans << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}