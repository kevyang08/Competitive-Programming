#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a[500005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("snake_scales_chapter_2_input.txt", "r", stdin);
    freopen("snake_scales_chapter_2_output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n;
        int ans = 0;
        vector<int> dist(n + 5);
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pq.push({-a[i], i});
            dist[i] = a[i];
        }
        while (!pq.empty()) {
            auto [d, c] = pq.top(); pq.pop();
            d = -d;
            if (dist[c] != d) continue;
            ans = max(ans, d);
            if (c > 1 && dist[c - 1] > max(d, abs(a[c] - a[c - 1]))) {
                dist[c - 1] = max(d, abs(a[c] - a[c - 1]));
                pq.push({-dist[c - 1], c - 1});
            }
            if (c < n && dist[c + 1] > max(d, abs(a[c] - a[c + 1]))) {
                dist[c + 1] = max(d, abs(a[c] - a[c + 1]));
                pq.push({-dist[c + 1], c + 1});
            }
        }
        cout << ans << "\n";
    }
    return 0;
}