#include <bits/stdc++.h>
using namespace std;

int n, p, q, a[2001], l = 1, r = 1e9, ans = 0x3f3f3f3f, dp[2001][2001], mx[2001][2];
bool check(int w) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n && a[i] + w > a[j]; j++) mx[i][0] = j;
        for (int j = i; j <= n && a[i] + 2 * w > a[j]; j++) mx[i][1] = j;
    }
    for (int i = 1; i <= p; i++) {
        dp[i][0] = mx[dp[i - 1][0] + 1][0];
        if (dp[i][0] == n) return true;
    }
    for (int i = 1; i <= q; i++) {
        dp[0][i] = mx[dp[0][i - 1] + 1][1];
        if (dp[0][i] == n) return true;
    }
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i][j] = max(mx[dp[i - 1][j] + 1][0], mx[dp[i][j - 1] + 1][1]);
            if (dp[i][j] == n) return true;
        }
    }
    return false;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> p >> q;
    p = min(n, p); q = min(n, q);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n + 1);
    while (l <= r) {
        int m = (l + r)/2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans << "\n";
    return 0;
}

/*
https://dmoj.ca/problem/joi13op3

- p = min(p, 2000), q = min(q, 2000)
- sort events by section
- binary search max w
- dp[i][j] is the furthest right event reachable by i small cameras and j large cameras
- start by precomputing mx[n][2], where mx[i][0] is max event reachable starting from event i
  with a small camera and mx[i][1] is max reachable starting from event i with a large camera
- next, calculate dp[0][1] to dp[0][q] and dp[1][0] to dp[p][0]
- then, dp[i][j] = max(mx[dp[i - 1][j] + 1][0], mx[dp[i][j - 1] + 1][1]), accounting for when
  dp[i - 1][j] == n or dp[i][j - 1] == n
- if dp[p][q] = n: ans = m, r = m - 1
- else l = m + 1
- time complexity: O(N^2log(max(A)))
- space complexity: O(N^2)
*/
