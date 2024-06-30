#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long n, m, thing = 0, temp = 0;
        cin >> n >> m;
        for (long long i = (1LL << 62); i >= 0 && (i & n) == (i & m); i >>= 1) if (i & n) thing += i, n -= i, m -= i;
        temp = n - (1LL << (63 - __builtin_clzll(n)));
        if (!thing && (!temp || __builtin_clzll(temp) > __builtin_clzll(m))) cout << "-1\n";
        else if (thing || (temp | ((1LL << (63 - __builtin_clzll(temp))) - 1)) == m) {
            cout << "1\n";
            cout << n + thing << " " << m + thing << "\n";
        }
        else {
            cout << "2\n";
            cout << n + thing << " " << thing + (temp | ((1LL << (63 - __builtin_clzll(temp))) - 1)) << " " << thing + m << "\n";
        }
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