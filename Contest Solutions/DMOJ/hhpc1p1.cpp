#include <bits/stdc++.h>
using namespace std;

int t, n, arr[1000001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = 1;
            if (i > 1 && s[i - 1] == s[i - 2]) arr[i] += arr[i - 1];
            mx = max(mx, arr[i] + 1);
        }
        for (int i = n; i > 0; i--) if (i < n && s[i] == s[i - 1]) arr[i] = arr[i + 1];
        for (int i = 1; i <= n; i++) {
            if (i > 1 && s[i - 1] != s[i - 2]) {
                if (i < n && s[i - 2] == s[i]) mx = max(mx, arr[i - 1] + arr[i + 1] + 1);
                else mx = max(mx, arr[i - 1] + 1);
            }
            else if (i < n && s[i - 1] != s[i]) mx = max(mx, arr[i + 1] + 1);
        }
        cout << min(mx, n) << "\n";
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
