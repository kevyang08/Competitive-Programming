#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1856/problem/D

- smth like merge sort??
- except you only care about the largest element
*/

int t, n;
int query(int l, int r) {
    if (l == r) return l;
    int m = (l + r)/2, a, b = 0, ml = query(l, m), mr = query(m + 1, r);
    cout << "? " << ml << " " << mr << endl;
    cin >> a;
    if (a && mr > ml + 1) {
        cout << "? " << ml << " " << mr - 1 << endl;
        cin >> b;
    }
    return (a == b ? mr : ml);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int res = query(1, n);
        cout << "! " << res << endl;
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