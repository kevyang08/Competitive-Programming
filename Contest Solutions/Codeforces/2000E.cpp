#include <bits/stdc++.h>
using namespace std;

int t, n, m, w, k, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> w;
        priority_queue<int> pq;
        priority_queue<long long>pq2;
        long long ans = 0;
        for (int i = 0; i < w; i++) {
            cin >> a;
            pq.push(a);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pq2.push((long long)min(min(i, n - i + 1), min(n - k + 1, k)) * min(min(j, m - j + 1), min(m - k + 1, k)));
            }
        }
        while (!pq.empty()) {
            ans += pq2.top() * pq.top();
            pq.pop(); pq2.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}