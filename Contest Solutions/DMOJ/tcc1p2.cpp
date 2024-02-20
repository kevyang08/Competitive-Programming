#include <bits/stdc++.h>
using namespace std;

int n, k, x[1000001], idx[1000001], cnt[1000001];
long long a[1000001], sum[1000001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= k; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) sum[i] = a[n];
    for (int i = n; i > 0; i--) {
        int temp = a[i] - a[i - 1];
        if (!idx[temp]) {
            idx[temp] = i;
            cnt[temp] = x[temp] + 1;
        }
        else if (idx[temp] - cnt[temp] < i) cnt[temp] = min(cnt[temp] + x[temp] + 1, n);
        else {
            sum[temp] -= a[idx[temp]] - a[max(idx[temp] - cnt[temp], 0)];
            idx[temp] = i;
            cnt[temp] = x[temp] + 1;
        }
    }
    for (int i = 1; i <= k; i++) sum[i] -= a[idx[i]] - a[max(idx[i] - cnt[i], 0)];
    for (int i = 1; i <= k; i++) cout << sum[i] << "\n";
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
