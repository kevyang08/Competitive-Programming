#include <bits/stdc++.h>
using namespace std;

int t, n, a[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        map<int, int> freq;
        set<int> seen;
        cin >> n;
        long long ans = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (seen.find(a[i]) == seen.end()) c++;
            seen.insert(a[i]);
            freq[a[i]]--;
            if (!freq[a[i]]) ans += c;
        }
        cout << ans << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/