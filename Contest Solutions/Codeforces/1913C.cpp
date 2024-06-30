#include <bits/stdc++.h>
using namespace std;

int t, n, op, x;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> t;
    // int t = 1;
    // while (t--) {
        cin >> n;
        vector<int> v(30), c(30);
        for (int i = 0; i < n; i++) {
            cin >> op >> x;
            if (op == 1) v[x]++;
            else {
                for (int i = 0; i < 30; i++) c[i] = 0;
                for (int i = 29; i >= 0; i--) {
                    if (!(x & (1 << i))) continue;
                    for (int j = i; j >= 0; j--) {
                        int temp = c[j];
                        c[j] += min(v[j] - temp, x/(1 << j));
                        x -= (1 << j) * min(v[j] - temp, x/(1 << j));
                    }
                }
                cout << (!x ? "YES\n" : "NO\n");
            }
        }
    // }
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