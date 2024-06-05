#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vector<int> v(7);
        for (char c : s) if (v[c - 'A'] < m) v[c - 'A']++;
        cout << m * 7 - accumulate(v.begin(), v.end(), 0) << "\n";
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
