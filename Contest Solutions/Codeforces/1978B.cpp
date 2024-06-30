#include <bits/stdc++.h>
using namespace std;

int t;
long long n, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        long long ans = 0;
        if (a >= b) ans = a * n;
        else {
            if (b - a < n) ans = b * (b + 1)/2 - a * (a + 1)/2 + a * (n - b + a);
            else ans = b * (b + 1)/2 - (b - n) * (b - n + 1)/2;
        }
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