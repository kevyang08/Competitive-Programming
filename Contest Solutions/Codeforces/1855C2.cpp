#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1855/problem/C2

- annoying problem
- can just brute force where to start positive and where to start negative probably
- O(N^3)
*/

int t, n, a[21];
bool check(int ndx, int pdx) {
    if (ndx > 0 && a[ndx] >= 0 || pdx <= n && a[pdx] <= 0) return false;
    vector<int> temp(n + 1);
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) temp[i] = a[i];
    for (int i = pdx; i < n; i++) {
        if (temp[i + 1] < 0) {
            while (temp[i] < -temp[i + 1]) {
                temp[i] += temp[i];
                v.push_back({i, i});
            }
            v.push_back({i + 1, i});
            temp[i + 1] += temp[i];
        }
        v.push_back({i + 1, i});
        temp[i + 1] += temp[i];
    }
    for (int i = ndx; i > 1; i--) {
        if (temp[i - 1] > 0) {
            while (temp[i] > -temp[i - 1]) {
                temp[i] += temp[i];
                v.push_back({i, i});
            }
            v.push_back({i - 1, i});
            temp[i - 1] += temp[i];
        }
        v.push_back({i - 1, i});
        temp[i - 1] += temp[i];
    }
    if (v.size() > 31) return false;
    for (int i = 1; i < n; i++) if (temp[i] > temp[i + 1]) return false;
    cout << v.size() << "\n";
    for (auto &[a, b] : v) cout << a << " " << b << "\n";
    return true;
}
void solve() {
    for (int i = 1; i <= n + 1; i++) for (int j = 0; j < i; j++) if (check(j, i)) return;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool thing = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            thing &= !a[i];
        }
        if (thing) {
            cout << "0\n";
            continue;
        }
        solve();
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