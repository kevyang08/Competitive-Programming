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
        cin >> n;
        long long sum = 0, move = 0;
        bool thing = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        for (int i = n; i > 0; i--) {
            if (a[i] < sum/n) move += sum/n - a[i];
            if (a[i] > sum/n) {
                if (a[i] - sum/n > move) thing = false;
                else move -= a[i] - sum/n;
            }
        }
        cout << (thing ? "YES\n" : "NO\n");
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
