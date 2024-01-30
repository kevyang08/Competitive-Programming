// don't need the solve function

#include <bits/stdc++.h>
using namespace std;
 
int t;
long long a, b, r;
long long solve() {
    long long aa = 0, bb = 0, bbb = 0;
    for (int i = 63; i >= 0; i--) {
        long long x = (1LL << i), xx = (a & x) ^ (b & x);
        if (!xx) continue;
        if (aa <= bb || bbb + xx > r && !(b & x)) aa += xx;
        else {
            bb += xx;
            if (!(b & x)) bbb += xx;
        }
        // cout << aa << " " << bb << " wtf\n";
    }
    return abs(aa - bb);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> r;
        if (a < b) swap(a, b);
        cout << solve() << "\n";
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
