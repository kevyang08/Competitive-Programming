#include <bits/stdc++.h>
using namespace std;

/*
best case:
- same color, only need one jump from i to j

other cases:
- only impossible if all cities are either AB or CD, and c[i] != c[j]
- else always possible with one stop
    - check in between first, then check outside
    - have sets of each possible color combo
*/

int t, n, q, x, y;
string s, c[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        map<string, set<int>> mp;
        map<string, set<int, greater<int>>> mpg;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            char a = s[0], b = s[1];
            if (a > b) swap(a, b);
            c[i] = string{a} + string{b};
            mp[c[i]].insert(i);
            mpg[c[i]].insert(i);
        }
        while (q--) {
            cin >> x >> y;
            if (x > y) swap(x, y);
            if (c[x][0] == c[y][0] || c[x][1] == c[y][0] || c[x][0] == c[y][1] || c[x][1] == c[y][1]) cout << y - x << "\n";
            else {
                int mn = 0x3f3f3f3f;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        char a = c[x][i], b = c[y][j];
                        if (a > b) swap(a, b);
                        string bruh = string{a} + string{b};
                        if (mp[bruh].upper_bound(x) != mp[bruh].end()) mn = min(mn, *mp[bruh].upper_bound(x) - x + abs(y - *mp[bruh].upper_bound(x)));
                        if (mpg[bruh].upper_bound(y) != mpg[bruh].end()) mn = min(mn, y - *mpg[bruh].upper_bound(y) + abs(*mpg[bruh].upper_bound(y) - x));
                    }
                }
                cout << (mn == 0x3f3f3f3f ? -1 : mn) << "\n";
            }
        }
    }
    return 0;
}