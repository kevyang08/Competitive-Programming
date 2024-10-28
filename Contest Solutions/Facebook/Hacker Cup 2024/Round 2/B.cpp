#include <bits/stdc++.h>
using namespace std;

/*
try brute force or smth i really dont know
store the board as a integer state

Post contest: ending the recursion (basically dfs) early caused some cases to be missed
*/

typedef long long ll;

int t, dr[4] = {1, 1, 1, 0}, dc[4] = {-1, 0, 1, 1};
bool vis[8000001];
string grid[6];
bool solve(char ch, int state, int turn, bool win) {

    // if (state == 7777634) cout << state << "here\n"; // debug
    // if (state == 7777644) cout << state << "here\n"; // debug
    // if (state == 7777744) cout << state << "here\n"; // debug

    //cout << state << " " << win << " " << vis[state][win] << " bruh\n";

    // if (state == 1111111) cout << win << " " << "here\n"; // debug

    if (vis[state]) return false;
    vis[state] = true;
    int temp = state;
    vector<int> v(7);
    for (int i = 0; i < 7; i++) {
        v[i] = temp%10 - 1;
        temp /= 10;
    }
    for (int k = 0; k < 4; k++) { // check win
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (v[j] > i || i + 3 * dr[k] > 5 || j + 3 * dc[k] < 0 || j + 3 * dc[k] > 6) continue;
                bool thing = true;
                char c = grid[i][j];
                for (int l = 1; l < 4; l++) {
                    if (v[j + l * dc[k]] > i + l * dr[k] || grid[i + l * dr[k]][j + l * dc[k]] != c) thing = false;
                }
                if (thing) {
                    if (!win && c != ch) return false;
                    else win = true;
                }
            }
        }
    }

    if (state == 1111111) return win;
    temp = 1;
    if (turn%2) {
        for (int i = 0; i < 7; i++) {
            if (!v[i] || grid[v[i] - 1][i] != 'F') {
                temp *= 10;
                continue;
            }
            if (solve(ch, state - temp, turn ^ 1, win)) {
                return true;
            }
            temp *= 10;
        }
    }
    else {
        for (int i = 0; i < 7; i++) {

            // if (state == 7777744) {
            //     cout << ch << " " << i << " " << v[i] << " debug\n";
            //     if (v[i]) cout << grid[v[i] - 1][i] << " bruh\n";
            // }

            if (!v[i] || grid[v[i] - 1][i] != 'C') {
                temp *= 10;
                continue;
            }
            if (solve(ch, state - temp, turn ^ 1, win)) {
                return true;
            }
            temp *= 10;
        }
    }
    return false;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("four_in_a_burrow_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        for (int i = 0; i < 6; i++) cin >> grid[i];

        for (int i = 0; i < 8000001; i++) vis[i] = false;
        bool cw = solve('C', 7777777, 0, false);

        for (int i = 0; i < 8000001; i++) vis[i] = false;
        bool fw = solve('F', 7777777, 0, false);

        if (cw && fw) cout << "?\n";
        else if (cw) cout << "C\n";
        else if (fw) cout << "F\n";
        else cout << "0\n";
    }
    return 0;
}

/*
1

CCFFFFF
CCCFCCF
CFCFCFC
FFFCCFF
FCCCFCC
CFFCFFC

output: ?
expected: C


1

CFFFFFF
CFFCFFF
CCCFFCC
CCFFCCC
FFCFCCF
CCCFCFC

output: ?
expected: F
*/