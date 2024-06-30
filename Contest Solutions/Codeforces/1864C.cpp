#include <bits/stdc++.h>
using namespace std;

int t, x;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x;
        vector<int> v;
        v.push_back(x);
        while (__builtin_popcount(x) > 1) {
            x -= (x & -x);
            v.push_back(x);
        }
        while (x > 1) {
            x /= 2;
            v.push_back(x);
        }
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
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