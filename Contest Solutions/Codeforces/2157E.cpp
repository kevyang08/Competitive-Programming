#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, k, a;
void solve() {
    cin >> n >> k;
    vector<int> freq(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ++freq[a];
    }
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r)/2, flag = 0;
        vector<int> tf(3 * n + 1);
        deque<int> dq;
        for (int i = m; i > 0; i--) dq.push_front(i + 2 * n);
        for (int i = 2 * n; i > 0; i--) {
            if (!freq[i]) {
                dq.push_front(i);
                continue;
            }
            while (!dq.empty() && dq.back() > i + m) dq.pop_back();
            int tmp = freq[i] - 1;
            tf[i] = 1;
            while (tmp && !dq.empty()) {
                ++tf[dq.front()];
                dq.pop_front();
                --tmp;
            }
            tf[i + m] += tmp;
            if (tf[i + m] > k) flag = 1;
        }

        // cout << m << " what\n";
        // for (int i = 1; i <= 2 * n + m; i++) cout << tf[i] << " ";
        // cout << "\nbruh\n"; // debug

        if (flag) l = m + 1;
        else r = m;
    }
    cout << l << "\n";
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