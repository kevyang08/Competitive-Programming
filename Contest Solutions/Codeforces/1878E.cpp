#include <bits/stdc++.h>
using namespace std;

int t, n, q, l, k, a[200005];
vector<vector<int>> nxt(30, vector<int>(200005));
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < 30; j++) {
                if (i == n || !((1 << j) & a[i])) nxt[j][i] = i;
                else nxt[j][i] = nxt[j][i + 1];
            }
        }
        cin >> q;
        while (q--) {
            cin >> l >> k;
            if (a[l] < k) {
                cout << "-1 ";
                continue;
            }
            int r = l, temp = a[l];
            priority_queue<int, vector<int>, greater<int>> pq;
            for (int j = 0; j < 30; j++) pq.push(nxt[j][l]);
            while (!pq.empty()) {
                temp &= a[pq.top()];
                if (temp < k) {
                    r = pq.top() - 1;
                    break;
                }
                r = pq.top();
                pq.pop();
            }
            cout << r << " ";
        }
        cout << "\n";
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
