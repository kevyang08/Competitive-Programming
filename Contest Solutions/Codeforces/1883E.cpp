#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0, cnt = 0;
        cin >> n >> a[1];
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            int temp = a[i];
            while (temp < a[i - 1]) {
                temp <<= 1;
                cnt++;
            }
            a[i - 1] <<= 1;
            while (a[i - 1] <= temp) {
                a[i - 1] <<= 1;
                cnt--;
            }
            cnt = max(cnt, 0LL);
            ans += cnt;
        }
        cout << ans << "\n";
    }
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
