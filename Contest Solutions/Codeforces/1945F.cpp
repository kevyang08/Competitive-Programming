#include <bits/stdc++.h>
using namespace std;

int t, n, v, p, idx[200001];
vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        arr.clear();
        for (int i = 1; i <= n; i++) {
            cin >> v;
            arr.push_back({i, v});
        }
        for (int i = 1; i <= n; i++) {
            cin >> p;
            idx[p] = i;
        }
        sort(arr.begin(), arr.end(), [&](auto a, auto b) {return idx[a.first] < idx[b.first];});
        for (int i = 1; 2 * i - 1 <= n; i++) pq.push(arr[n - i].second);
        if (n%2 == 0 && arr[n/2 - 1].second > pq.top()) {
            pq.pop();
            pq.push(arr[n/2 - 1].second);
        }
        long long sz = pq.size(), mx = (long long)pq.top() * sz;
        for (int i = n/2 + n%2 - 2; i >= 0; i--) {
            pq.pop();
            if (arr[i].second > pq.top()) {
                pq.pop();
                pq.push(arr[i].second);
            }
            if ((long long)pq.top() * pq.size() >= mx) {
                sz = pq.size();
                mx = (long long)pq.top() * sz;
            }
        }
        pq.pop();
        cout << mx << " " << sz << "\n";
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
