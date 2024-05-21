#include <bits/stdc++.h>
using namespace std;

// can also use sorted arrays with two pointers and a set to keep track of ones that were already cut

int t, a, b, n, m, x, y, k;
char c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        map<int, set<int>> mpx, mpy;
        int sa = 0, sb = 0, la = 1, lb = 1;
        cin >> a >> b >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            mpx.emplace(x, set<int>());
            mpy.emplace(y, set<int>());
            mpx[x].insert(y);
            mpy[y].insert(x);
        }
        for (int i = 1; i <= m; i++) {
            int res = 0;
            cin >> c >> k;
            if (c == 'U') {
                for (auto it = mpx.begin(); it != mpx.end(); it++) {
                    if (it -> first > la + k - 1) break;
                    res += it -> second.size();
                    for (int j : it -> second) {
                        mpy[j].erase(it -> first);
                        if (mpy[j].empty()) mpy.erase(j);
                    }
                }
                while (!mpx.empty() && mpx.begin() -> first <= la + k - 1) mpx.erase(mpx.begin());
                la += k;
            }
            else if (c == 'D') {
                for (auto it = mpx.rbegin(); it != mpx.rend(); it++) {
                    if (it -> first < a - k + 1) break;
                    res += it -> second.size();
                    for (int j : it -> second) {
                        mpy[j].erase(it -> first);
                        if (mpy[j].empty()) mpy.erase(j);
                    }
                }
                while (!mpx.empty() && mpx.rbegin() -> first >= a - k + 1) mpx.erase(mpx.rbegin() -> first);
                a -= k;
            }
            else if (c == 'L') {
                for (auto it = mpy.begin(); it != mpy.end(); it++) {
                    if (it -> first > lb + k - 1) break;
                    res += it -> second.size();
                    for (int j : it -> second) {
                        mpx[j].erase(it -> first);
                        if (mpx[j].empty()) mpx.erase(j);
                    }
                }
                while (!mpy.empty() && mpy.begin() -> first <= lb + k - 1) mpy.erase(mpy.begin());
                lb += k;
            }
            else {
                for (auto it = mpy.rbegin(); it != mpy.rend(); it++) {
                    if (it -> first < b - k + 1) break;
                    res += it -> second.size();
                    for (int j : it -> second) {
                        mpx[j].erase(it -> first);
                        if (mpx[j].empty()) mpx.erase(j);
                    }
                }
                while (!mpy.empty() && mpy.rbegin() -> first >= b - k + 1) mpy.erase(mpy.rbegin() -> first);
                b -= k;
            }
            if (i%2) sa += res;
            else sb += res;
        }
        cout << sa << " " << sb << "\n";
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
