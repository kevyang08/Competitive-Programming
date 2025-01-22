#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// why am i seeing so many stack problems

int t, n, m, k, d[100005], a[100005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int ans = 0;
        d[n + 1] = INF;
        stack<pair<int, int>> st; // (day, amt)
        for (int i = 1; i <= n; i++) cin >> d[i] >> a[i];
        for (int i = 1; i <= n; i++) {
            st.push({d[i], a[i]});
            int cur = 0, rem = m;
            while (!st.empty() && d[i] + cur < d[i + 1] && st.top().fi + k - 1 >= d[i] + cur) {
                if (st.top().se <= rem) {
                    rem -= st.top().se;
                    if (!rem) ++cur, ++ans, rem = m;
                    st.pop();
                }
                else {
                    ++cur, ++ans;
                    st.top().se -= rem;
                    rem = m;
                    int tmp = min(d[i + 1], st.top().fi + k) - d[i] - cur;
                    if (tmp > st.top().se/m) tmp = st.top().se/m;
                    cur += tmp, ans += tmp;
                    st.top().se -= tmp * m;
                    if (min(d[i + 1], st.top().fi + k) > d[i] + cur) {
                        rem -= st.top().se;
                        st.pop();
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
5 2 4
4 7
5 3
7 1
11 2
12 1

expected: 5
got: 4
*/