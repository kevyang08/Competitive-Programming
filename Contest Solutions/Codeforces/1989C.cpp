#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001], b[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (a[i] > -1 && b[i] != 1) s1 += a[i];
            else if (a[i] != 1 && b[i] > -1) s2 += b[i];
            else v.push_back(a[i]); // a[i] == b[i]
        }
        for (auto &i : v) {
            if (i < 0) {
                if (s1 > s2) s1--;
                else s2--;
            }
            else {
                if (s1 < s2) s1++;
                else s2++;
            }
        }
        cout << min(s1, s2) << "\n";
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