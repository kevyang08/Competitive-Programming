#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1903/problem/E

- count and store points with even and odd distances from start
- first player strat:
    - if even >= odd: keep taking odd
        - whatever the opponent takes, odd will run out first, and the result is forced to be even
    - else no winning strat:
        - opponent keeps taking even, even will run out first, and the result is forced to be odd
- second player strat:
    - reverse first player strat
*/

int t, n, sx, sy, x, y;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> sx >> sy;
        set<int> e, o;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y;
            if ((abs(x - sx) + abs(y - sy))%2) o.insert(i);
            else e.insert(i);
        }
        if (e.size() < o.size()) {
            cout << "Second" << endl;
            for (int i = 0; i < n; i++) {
                if (i%2) {
                    if (e.size()) {
                        cout << *e.begin() << endl;
                        e.erase(e.begin());
                    }
                    else {
                        cout << *o.begin() << endl;
                        o.erase(o.begin());
                    }
                }
                else {
                    cin >> x;
                    if (o.find(x) != o.end()) o.erase(x);
                    else e.erase(x);
                }
            }
        }
        else {
            cout << "First" << endl;
            for (int i = 0; i < n; i++) {
                if (i%2) {
                    cin >> x;
                    if (o.find(x) != o.end()) o.erase(x);
                    else e.erase(x);
                }
                else {
                    if (o.size()) {
                        cout << *o.begin() << endl;
                        o.erase(o.begin());
                    }
                    else {
                        cout << *e.begin() << endl;
                        e.erase(e.begin());
                    }
                }
            }
        }
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