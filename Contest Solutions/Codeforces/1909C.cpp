#include <bits/stdc++.h>
using namespace std;

int t, n, c, r;
vector<int> l;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n;
        l.resize(n);
        priority_queue<int> pq;
        set<int> s;
        vector<long long> v;
        for (int i = 0; i < n; i++) cin >> l[i];
        for (int i = 0; i < n; i++) {
            cin >> r;
            s.insert(r);
        }
        sort(l.begin(), l.end());
        for (int i = n - 1; i >= 0; i--) {
            v.push_back(*s.lower_bound(l[i]) - l[i]);
            s.erase(*s.lower_bound(l[i]));
        }
        for (int i = 0; i < n; i++) {
            cin >> c;
            pq.push(c);
        }
        sort(v.begin(), v.end());
        for (auto i : v) ans += i * pq.top(), pq.pop();
        cout << ans << "\n";
    }
    return 0;
}
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spammaxg submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/