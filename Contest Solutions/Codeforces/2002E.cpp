#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        deque<pair<int, ll>> dq;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            ll cur = a, mx = 0;
            while (!dq.empty()) {
                if (dq.back().fi != b && dq.back().se > cur) break;
                if (dq.back().fi == b) cur += dq.back().se - mx;
                else mx = dq.back().se;
                dq.pop_back();
            }
            dq.push_back({b, cur});
            cout << dq.front().se << " ";
        }
        cout << "\n";
    }
    return 0;
}