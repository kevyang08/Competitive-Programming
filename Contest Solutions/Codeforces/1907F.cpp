#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> v;
int check(int r) {
    if (r) reverse(v.begin(), v.end());
    int ans = 0, c = 0, idx = -1;
    for (int i = 1; i < n; i++) if (v[i] < v[i - 1]) {
        if (c) return 0x3f3f3f3f;
        else {
            idx = i - 1;
            c = 1;
        }
    }
    if (idx != -1 && v[n - 1] > v[0]) return 0x3f3f3f3f;
    if (idx == -1) return r;
    return min(idx + 3 - r, n - idx - 1 + r);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int r1 = check(0), r2 = check(1);
        if (r1 != 0x3f3f3f3f || r2 != 0x3f3f3f3f) cout << min(r1, r2) << "\n";
        else cout << "-1\n";
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
