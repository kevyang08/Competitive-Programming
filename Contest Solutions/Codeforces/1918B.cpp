// definitely overcomplicated, only need to sort either a or b without checking

#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[200001], b[200001], bit[200001];
void update(int i) {
    for (; i <= n; i += (i & -i)) bit[i]++;
}
int query(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        long long a1 = 0, a2 = 0;
        vector<pair<int, int>> v1, v2;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            v1.push_back({a[i], b[i]});
            v2.push_back({b[i], a[i]});
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (auto &[a, b] : v1) {
            a1 += query(n) - query(b);
            update(b);
        }
        for (int i = 1; i <= n; i++) bit[i] = 0;
        for (auto &[a, b] : v2) {
            a1 += query(n) - query(b);
            update(b);
        }
        for (int i = 1; i <= n; i++) bit[i] = 0;
        if (a1 < a2) {
            for (int i = 0; i < n; i++) cout << v1[i].first << (i == n - 1 ? "\n" : " ");
            for (int i = 0; i < n; i++) cout << v1[i].second << (i == n - 1 ? "\n" : " ");
        }
        else {
            for (int i = 0; i < n; i++) cout << v2[i].second << (i == n - 1 ? "\n" : " ");
            for (int i = 0; i < n; i++) cout << v2[i].first << (i == n - 1 ? "\n" : " ");
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
