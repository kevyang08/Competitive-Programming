#include <bits/stdc++.h>
using namespace std;

int t, n, h[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = 0, p = 0;
        for (int i = 1; i <= n; i++) cin >> h[i];
        mx = p = h[n];
        for (int i = n - 1; i > 0; i--) {
            if (h[i] <= h[i + 1]) ++p;
            else {
                if (h[i] > p) p = h[i];
                else ++p; 
            }
            mx = max(mx, p);
        }
        cout << mx << "\n";
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