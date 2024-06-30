#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1864/problem/B

- probably a constructive problem :thumbs_down:
- if even can probably just sort it
- else just sort even and odd
*/

int t, n, k;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        if (k%2) {
            vector<char> v[2];
            for (int i = 0; i < n; i++) v[i%2].push_back(s[i]);
            sort(v[0].begin(), v[0].end());
            sort(v[1].begin(), v[1].end());
            for (int i = 0; i < n; i++) cout << v[i%2][i/2];
        }
        else {
            sort(s.begin(), s.end());
            cout << s;
        }
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