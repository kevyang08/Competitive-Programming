#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        d -= d%2;
        if ((a + c)%2 && (b + c)%2) {
            if (c) c--;
            else {
                a--;
                b--;
            }
        }
        else {
            if ((a + c)%2) {
                if (a) a--;
                else {
                    c--;
                    b--;
                }
            }
            if ((b + c)%2) {
                if (b) b--;
                else {
                    c--;
                    a--;
                }
            }
        }
        cout << (a + c)/2 + (b + c)/2 - c/2 - c%2 + d/2 << "\n";
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
