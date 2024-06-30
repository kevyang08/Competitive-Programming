#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans = 0, i = n - 1, l = 0, x = 0;
        a.resize(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        for (; i > l; i--) {
            ans++;
            while (l < i && x + a[l] < a[i]) ans += a[l], x += a[l++];
            if (l == i) {
                a[i] -= x;
                ans += a[i]/2 + a[i]%2;
                i = -1;
                break;
            }
            else if (l + 1 == i) {
                ans += a[i] - x;
                x = a[l] - a[i] + x;
                ans += x/2 + (x > 1 ? x%2 : 0) + (x > 0);
                break;
            }
            else {
                x = a[l] - a[i] + x;
                ans += a[l++];
            }
        }
        if (l == i) ans += (a[i] - x)/2 + (a[i] > 1 ? (a[i] - x)%2 : 0) + 1;
        cout << ans << "\n";
    }
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