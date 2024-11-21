#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// post-submission: every mask only has one possible value of idx since we know that if there are k bits
// in the mask, then the current index must be k + 1
// still way slower than bottom up though

const int M = 1e9 + 7;

int n, a[22][22];
ll dp[1 << 22];
ll ways(int m, int idx) {
    if (idx > n) return 1;
    if (dp[m] != -INFL) return dp[m];
    dp[m] = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[idx][i] || ((1 << i) & m)) continue;
        dp[m] = (dp[m] + ways(m | (1 << i), idx + 1))%M;
    }
    return dp[m];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int j = 0; j <= (1 << (n + 1)); j++) dp[j] = -INFL;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    cout << ways(0, 1) << "\n";
    return 0;
}