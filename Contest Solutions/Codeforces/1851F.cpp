#include <bits/stdc++.h>
using namespace std;

int t, n, k, a, i, j, x, mx;
vector<pair<int, int>> v;
void solve(int l, int r, int idx) {
    if (r - l < 1) return;
    if (idx < 0) {
        i = v[l].second, j = v[r].second;
        mx = (1 << k) - 1;
        x = (1 << k) - 1 - v[l].first;
        return;
    }
    if (r - l == 1) {
        int res = 0, temp = 0;
        for (int i = (1 << (k - 1)); i > 0; i >>= 1) {
            if ((v[l].first & i) == (v[r].first & i)) {
                res += i;
                if (!(v[l].first & i)) temp += i;
            }
        }
        if (res > mx) {
            i = v[l].second, j = v[r].second;
            mx = res;
            x = temp;
            return;
        }
    }
    int lo = l - 1, hi = r;
    while (lo < hi) {
        int m = (lo + hi + 1)/2;
        if (v[m].first & (1 << idx)) hi = m - 1;
        else lo = m;
    }
    solve(l, lo, idx - 1), solve(lo + 1, r, idx - 1);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        mx = 0, i = 1, j = 2, x = 0;
        v.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a;
            v.push_back({a, i});
        }
        sort(v.begin(), v.end());
        solve(0, n - 1, k - 1);
        cout << i << " " << j << " " << x << "\n";
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