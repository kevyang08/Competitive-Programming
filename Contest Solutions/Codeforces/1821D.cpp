#include <bits/stdc++.h>
using namespace std;

/*
- on the last one, try to remove as many ones as possible, saving 1 move each
- maybe can also try going through all to save as much on ones as possible
*/

int t, n, k, l[200001], r;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = -1, c = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> l[i];
        for (int i = 1; i <= n; i++) {
            cin >> r;
            if (c + r - l[i] + 1 >= k) while (!pq.empty() && pq.top() == 1 && c - 1 + r - l[i] + 1 >= k) pq.pop(), --c;
            if (c < k) {
                pq.push(r - l[i] + 1);
                int temp = min(r - l[i] + 1, k - c);
                c += r - l[i] + 1;
                if (c >= k && (ans == -1 || l[i] + temp - 1 + pq.size() * 2 < ans)) ans = l[i] + temp - 1 + pq.size() * 2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}