#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1869/problem/D1

- must form cycle
- total candies must be divisible by n
- each persons initial candies must be avg + 2^x - 2^y for some x, y >= 0
*/

int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        map<int, int> in, out;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum%n) {
            cout << "No\n";
            continue;
        }
        int avg = sum/n;
        bool ans = true;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            bool thing = false;
            for (int j = 0; j < 31; j++) if (bitset<32>(a[i] + (1 << j) - avg).count() == 1) {
                in[(1 << j)]++;
                out[a[i] + (1 << j) - avg]++;
                thing = true;
            }
            if (!thing) ans = false;
        }
        for (auto &[i, v] : in) if (out.find(i) == out.end() || out[i] != v) ans = false;
        for (auto &[i, v] : out) if (in.find(i) == in.end() || in[i] != v) ans = false;
        cout << (ans ? "Yes\n" : "No\n");
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

/*
4 3
1 2 0
2 0 1
1 2 0
2 0 1
*/