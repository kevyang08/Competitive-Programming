#include <bits/stdc++.h>
using namespace std;

int t;
bool check(int n) {
    for (int i = 2; i * i <= n; i++) if (n%i == 0) return false;
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        bool thing = false;
        cin >> n;
        for (int i = 100000000; i > 1; i /= 10) {
            for (int j = 10000000; j > 0; j /= 10) if (check(n/i%10 * 10 + n/j%10)) {
                thing = true;
                cout << n/i%10 * 10 + n/j%10 << "\n";
                break;
            }
            if (thing) break;
        }
        if (!thing) cout << "-1\n";
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
