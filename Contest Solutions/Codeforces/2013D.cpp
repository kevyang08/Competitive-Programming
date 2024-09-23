#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
ll a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        stack<pair<ll, int>> st;
        cin >> n;
        ll mn = 0x3f3f3f3f3f3f3f3f, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            while (!st.empty() && st.top().first > a) {
                ll l = 0, r = st.top().first - a, cur = st.top().first, cnt = st.top().second;
                st.pop();
                while (l < r) {
                    ll m = (l + r + 1)/2;
                    if ((st.empty() || cur - m/cnt - (m%cnt ? 1 : 0) >= st.top().first) && cur - m/cnt >= a + m) l = m;
                    else r = m - 1;
                }
                if (!l) {
                    st.push({cur, cnt});
                    break;
                }
                ll tmp = l/cnt, rm = l%cnt;
                a += l;

                // cout << i << " " << cur << " " << cnt << " " << l << " bruh\n";

                if (st.empty() || cur - tmp - (rm ? 1 : 0) > st.top().first) st.push({cur - tmp - (rm ? 1 : 0), 0});
                if (cur - tmp - (rm ? 1 : 0) == st.top().first) {
                    st.top().second += rm;
                    if (!rm) st.top().second += cnt, cnt = 0;
                    else cnt -= rm;
                }
                if (cnt) st.push({cur - tmp, cnt});

                // cout << st.top().first << " " << st.top().second << " what\n";
            }
            if (!st.empty() && a == st.top().first - 1) {
                auto [cur, cnt] = st.top(); st.pop();
                if (!st.empty() && st.top().first == cur - 1) ++st.top().second;
                else st.push({cur - 1, 1});
                st.push({cur, cnt - 1}); // since we add 1 back later
            }
            else if (st.empty() || a > st.top().first) st.push({a, 0});
            ++st.top().second;

            // cout << st.size() << " " << st.top().first << " " << st.top().second << " check\n";
        }
        mx = st.top().first;
        while (st.size() > 1) st.pop();
        mn = st.top().first;
        cout << mx - mn << "\n";
    }
    return 0;
}