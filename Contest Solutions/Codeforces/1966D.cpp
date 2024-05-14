// intuition of excluding leading bit was correct,
// reasoning out the remaining stuff needs work

#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        vector<int> v;
        cin >> n >> k;
        int thing = 1 << (31 - __builtin_clz(k));
        v.push_back(k - thing); v.push_back(k + 1); v.push_back(k + 1 + thing);
        for (int i = 1; i <= n; i <<= 1) if (i != thing) v.push_back(i);
        cout << v.size() << "\n";
        for (int i : v) cout << i << " ";
        cout << "\n";
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
