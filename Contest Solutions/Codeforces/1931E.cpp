#include <bits/stdc++.h>
using namespace std;
 
int t, n, m, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pair<int, int>> v;
        deque<pair<int, int>> dq;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            string temp = to_string(a[i]);
            int cnt = 0, len = temp.size();
            while (a[i] > 0 && a[i]%10 == 0) {
                cnt++;
                a[i] /= 10;
            }
            v.push_back({cnt, len});
            // cout << cnt << " " << len << " wtf\n";
        }
        sort(v.begin(), v.end());
        for (auto p : v) dq.push_front(p);
        do {
            auto p = dq.front(); dq.pop_front();
            if (dq.empty()) {
                dq.push_back({0, p.second - p.first});
                break;
            }
            auto q = dq.front(); dq.pop_front();
            dq.push_back({0, q.second + p.second - p.first});
        } while (dq.size() > 1);
 
        // cout << dq.front().second << " wtf\n";
        cout << (dq.front().second > m ? "Sasha\n" : "Anna\n");
    }
    return 0;
}
 
/*
1
4 10
1 2007 800 1580
 
*/
 
/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
