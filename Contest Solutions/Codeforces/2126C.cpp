#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, h;
void solve() {
    cin >> n >> k;
    int c = 0, w = 1;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> h;
        pq.push(-h);
        if (i + 1 == k) c = h;
    }
    while (!pq.empty() && -pq.top() <= c) pq.pop();
    while (!pq.empty()) {
        if (-pq.top() - c > c - w + 1) break;
        w += -pq.top() - c;
        c = -pq.top();
        pq.pop();
    }
    cout << (pq.empty() ? "YES\n" : "NO\n");
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}