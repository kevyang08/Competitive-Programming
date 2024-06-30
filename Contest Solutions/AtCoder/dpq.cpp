#include <bits/stdc++.h>
using namespace std;

int n, h[200001], a;
long long bit[200001], ans = 0;
long long query(int i) {
    long long res = 0;
    for (; i > 0; i -= (i & -i)) res = max(res, bit[i]);
    return res;
}
void update(int i, long long v) {
    for (; i <= n; i += (i & -i)) bit[i] = max(bit[i], v);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) {
        cin >> a;
        long long res = query(h[i]) + a;
        update(h[i] + 1, res);
        ans = max(ans, res);
    }
    cout << ans << "\n";
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/