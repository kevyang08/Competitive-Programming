#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, m1, m2, a[30], b[30];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout << fixed << setprecision(9);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    vector<int> v;
    priority_queue<pair<int, int>> pq;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        cin >> a[i];
        pq.push({-a[i], a[i]});
    }
    cin >> m2;
    for (int i = 0; i < m2; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        auto [cur, dt] = pq.top(); pq.pop();
        v.push_back(-cur);
        pq.push({cur - dt, dt});
    }
    while (!pq.empty()) pq.pop();
    int l = 1, r = 50000;
    while (l < r) {
        int m = (l + r)/2;
        bool flag = true;
        for (int i = 0; i < m2; i++) pq.push({m - b[i], b[i]});
        for (int i = n - 1; i >= 0; i--) {
            auto [cur, dt] = pq.top(); pq.pop();
            if (cur < v[i]) {
                flag = false;
                break;
            }
            pq.push({cur - dt, dt});
        }
        while (!pq.empty()) pq.pop();
        if (flag) r = m;
        else l = m + 1;
    }
    cout << v.back() << "\n" << l << "\n";
    return 0;
}