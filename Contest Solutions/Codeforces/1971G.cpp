#include <bits/stdc++.h>
using namespace std;

int t, n, a, x = INT_MAX - 3, idx[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (mp.find(a & x) == mp.end()) mp[a & x] = priority_queue<int, vector<int>, greater<int>>();
            mp[a & x].push(a);
            idx[i] = a & x;
        }
        for (int i = 1; i <= n; i++) {
            cout << mp[idx[i]].top() << (i == n ? "\n" : " ");
            mp[idx[i]].pop();
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
