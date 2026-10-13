#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, k, a[200005];
bool check(int mk) {
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) pq.push(a[i]);
    for (int i = k + 2 * mk + n - 1; i >= k; i--) {
        while (!pq.empty() && pq.top() > i) {
            if (!mk) return false;
            --mk;
            int tmp = pq.top(); pq.pop();
            pq.push(tmp - tmp/2);
            pq.push(tmp - tmp/2);
        }
        if (!pq.empty()) pq.pop();
    }
    return true;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r)/2;
        if (check(m)) r = m;
        else l = m + 1;
    }
    cout << n + 2 * l << "\n";
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout << fixed << setprecision(9);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}