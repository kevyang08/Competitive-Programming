// could just use freq arrays for lower time complexity

#include <bits/stdc++.h>
using namespace std;
 
int t, n, m, k, x;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        bool thing = true;
        set<int> a, b;
        int cnta = 0, cntb = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            b.insert(x);
        }
        for (int i = 1; i <= k; i++) {
            if (a.find(i) != a.end() && b.find(i) != b.end()) continue;
            else if (a.find(i) != a.end()) cnta++;
            else if (b.find(i) != b.end()) cntb++;
            else thing = false;
        }
        cout << (thing && cnta <= k/2 && cntb <= k/2 ? "YES\n" : "NO\n");
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
