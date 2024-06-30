#include <bits/stdc++.h>
using namespace std;

int t, n, l;
vector<pair<long long, long long>> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> l;
        v.resize(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i].second >> v[i].first; // switch a and b to sort by b
            if (v[i].second <= l) ans = 1;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++) {
            long long s = v[i].second;
            priority_queue<long long> pq;
            pq.push(s);
            for (int j = i + 1; j < n; j++) {
                pq.push(v[j].second);
                s += v[j].first - v[j - 1].first + v[j].second;
                while (s > l && !pq.empty()) s -= pq.top(), pq.pop();
                if (s <= l) ans = max(ans, static_cast<int>(pq.size()));
            }
        }
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