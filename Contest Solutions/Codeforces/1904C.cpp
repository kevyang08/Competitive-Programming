#include <bits/stdc++.h>
using namespace std;

int t, n, k;
vector<long long> a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        long long mn = a[0];
        if (k <= 2) {
            for (int i = 1; i < n; i++) mn = min(mn, a[i] - a[i - 1]);
            if (k == 2) {
                for (int i = 0; i < n - 1; i++) {
                    int idx = 0;
                    for (int j = i + 1; j < n; j++) {
                        while (idx + 1 < n && a[idx + 1] < a[j] - a[i]) idx++;
                        mn = min(mn, abs(a[j] - a[i] - a[idx]));
                        if (idx + 1 < n) mn = min(mn, abs(a[idx + 1] - a[j] + a[i]));
                    }
                }
            }
        }
        else mn = 0;
        cout << mn << "\n";
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