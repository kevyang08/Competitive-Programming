#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1864/problem/D

- wish i could think of a simpler solution, but the best one i can think of is a fricking rotated fenwick tree
- hopefully this is not the intended solution
*/

int t, n;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n;
        vector<vector<int>> bit(2 * n + 5, vector<int>(2 * n + 5));
        auto update = [&](int i, int j) {
            for (; i < 2 * n + 5; i += (i & -i)) for (int k = j; k < 2 * n + 5; k += (k & -k)) bit[i][k]++;
        };
        auto query = [&](int i, int j) {
            int res = 0;
            for (; i > 0; i -= (i & -i)) for (int k = j; k > 0; k -= (k & -k)) res += bit[i][k];
            return res;
        };
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 1; j <= n; j++) {
                int r = i + n - j, c = i + j - 1, val = query(r, c) + (s[j - 1] == '1');
                if (val%2) {
                    ++ans;
                    update(r, c);
                }
            }
        }
        cout << ans << "\n";
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