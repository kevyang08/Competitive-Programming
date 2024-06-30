#include <bits/stdc++.h>
using namespace std;

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
        int len = 1, idx = n - k, l = 0;
        bool thing = true, ans = true;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] != s[n - 1] || len == k) break;
            else ++len;
        }
        if (len < k) {
            for (int i = n - len - 1; i >= 0; i--) {
                if (s[i] != s[i + 1]) {
                    if (thing && s[i] != s[n - 1] && l%k == k - len && l < 2 * k) idx = i + l%k + 1;
                    else if (l%k || l > k) ans = false;
                    if (s[i] != s[n - 1] && (l%k || l > k)) thing = false;
                    l = 0;
                }
                ++l;
            }
            if (thing && s[0] == s[n - 1] && l%k == k - len && l < 2 * k) idx = l%k;
            else if (l%k || l > k) ans = false;
        }
        else {
            for (int i = n - k - 1; i >= 0; i--) {
                if (s[i] != s[i + 1]) {
                    if (l%k || l > k) {
                        if (s[i] == s[n - 1] && l == 2 * k && idx == n - k) idx = i + k + 1;
                        else ans = false;
                    }
                    l = 0;
                }
                ++l;
            }
            if (k != n && s[n - k - 1] == s[n - 1]) ans = false;
            if (l%k || l > k) {
                if (s[0] != s[n - 1] && l == 2 * k && idx == n - k) idx = k;
                else ans = false;
            }
            if (n == k && ans) idx = k;
        }
        cout << (ans ? idx : -1) << "\n";
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