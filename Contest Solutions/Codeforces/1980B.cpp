#include <bits/stdc++.h>
using namespace std;

int t, n, f, k;
vector<int> a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> f >> k;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        f = a[f - 1];
        sort(a.begin(), a.end(), greater<int>());
        cout << (a[k - 1] > f ? "NO\n" : k < n && a[k - 1] == f && a[k] == f ? "MAYBE\n" : "YES\n");
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
