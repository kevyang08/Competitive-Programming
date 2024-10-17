#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, r[2000001], bit[2][5001], dp[5001], tmp[5001], ans = 0, c = 1;
void update(int k, int i, int v) {
    for (; i <= m; i += (i & -i)) bit[k][i] += v;
}
int query(int k, int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[k][i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    int idx = 1;
    for (int i = 1; i <= n; i++) cin >> r[i];
    while (r[idx]) ++idx;
    while (idx <= n) {
        int j = idx + 1;
        for (; j <= n && r[j]; j++) {
            if (r[j] < 0) update(0, -r[j], 1);
            else update(1, r[j], 1);
        }
        for (int i = 0; i <= c; i++) {
            tmp[i] = max(dp[i - 1], dp[i]) + query(0, i) + query(1, c - i);
            ans = max(ans, tmp[i]);
        }
        for (int i = 0; i <= c; i++) dp[i] = tmp[i];
        for (int i = idx + 1; i < j; i++) {
            if (r[i] < 0) update(0, -r[i], -1);
            else update(1, r[i], -1);
        }
        idx = j;
        ++c;
    }
    cout << ans << "\n";
    return 0;
}