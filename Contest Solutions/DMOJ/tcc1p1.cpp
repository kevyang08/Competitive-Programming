#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0, idx = -1;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'Y') {
            idx = i;
            cnt++;
        }
        else if (idx != -1) cnt++;
    }
    cout << (cnt > n/2 ? "YES\n" : "NO\n");
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
