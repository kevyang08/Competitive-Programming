#include <bits/stdc++.h>
using namespace std;

int t;
bool thing[5001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        memset(thing, 0, sizeof(thing));
        string a, b;
        cin >> a >> b;
        int n = a.length();
        thing[0] = true;
        for (int i = 1; i <= n; i++) {
            if (!thing[i - 1]) continue;
            for (int j = i; j <= n; j++) if (a[i - 1] == a[j - 1] && b[i - 1] == b[j - 1] && a[i - 1] == b[i - 1]) thing[j] = true;
        }
        cout << (thing[n] ? "YES" : "NO") << "\n";
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
