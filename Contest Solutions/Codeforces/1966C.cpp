// overcomplicated solution, read editorial
// basically if Alice isn't forced into a losing position
// at the start, then she can always win by either
// maintaining a winning position or by forcing Bob
// into a losing one

#include <bits/stdc++.h>
using namespace std;

int t, n, a;
bool dp[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        vector<int> v;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }
        v.push_back(0);
        sort(v.begin(), v.end());
        dp[n] = true;
        int prev = n;
        for (int i = n - 1; i > 0; i--) {
            if (v[i] == v[i + 1]) dp[i] = dp[i + 1];
            else if (!dp[i + 1]) dp[i] = true;
            else {
                while (prev && v[prev] >= v[i]) prev--;
                dp[i] = v[i] - v[prev] > 1;
            }
        }
        cout << (dp[1] ? "Alice" : "Bob") << "\n";
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
