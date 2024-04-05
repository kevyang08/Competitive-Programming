#include <bits/stdc++.h>
using namespace std;

int a, b, cx = 0, cy = 0;
long long c, x = 0, y = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    for (long long i = 1; i <= c; i <<= 1) {
        if (!(i & c)) continue;
        if (a - cx >= b - cy) {
            cx++;
            x |= i;
        }
        else {
            cy++;
            y |= i;
        }
    }
    if (a > cx && b > cy && a - cx == b - cy) {
        for (int i = 0; i < 60; i++) {
            long long t = 1LL << i;
            if (t & c) continue;
            x |= t; y |= t; cx++; cy++;
            if (cx == a) break;
        }
    }
    if (cx != a || cy != b) cout << "-1\n";
    else cout << x << " " << y << "\n";
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
