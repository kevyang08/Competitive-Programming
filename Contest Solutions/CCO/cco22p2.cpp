#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, b[1000005], p[1000005], u[1000005], ab[1000005], abn[1000005], au[1000005], bruh[1000005];
ll ans = 0;
stack<int> st;
stack<pair<int, int>> stm;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i < n; i++) cin >> p[i];
    for (int i = 1; i < n; i++) cin >> u[i];
    int tmp = min(b[n], p[n - 1]);
    abn[n - 1] += tmp, p[n - 1] -= tmp, b[n] -= tmp;
    for (int i = 1; i < n; i++) {
        tmp = min(b[i], p[i]);
        ab[i] += tmp, p[i] -= tmp;
        tmp = min(b[i + 1], p[i]);
        abn[i] += tmp;
        b[i + 1] -= tmp, p[i] -= tmp;
        ans += p[i];
        if (p[i] > u[i]) {
            au[i] = u[i];
            p[i] -= u[i], u[i] = 0;
            int mn = INF, idx = -1;
            while (p[i] && !st.empty()) {
                int cur = st.top(); st.pop();
                while (!stm.empty() && stm.top().fi >= cur) {
                    mn = min(stm.top().se, mn);
                    idx = stm.top().fi;
                    stm.pop();
                }
                tmp = min(min(mn, p[i]), u[cur]);
                u[cur] -= tmp, abn[cur] -= tmp, p[i] -= tmp, ab[i] += tmp;
                au[cur] += tmp;
                bruh[cur + 1] += tmp; bruh[i] -= tmp;
                mn -= tmp;
                while (!stm.empty() && stm.top().se >= mn) stm.pop();
                stm.push({idx, mn});
                if (u[cur] && mn) st.push(cur);
            }
            if (p[i]) {
                cout << "NO\n";
                return 0;
            }
        }
        else {
            au[i] += p[i];
            u[i] -= p[i];
            if (u[i]) st.push(i);
        }
        while (!stm.empty() && stm.top().se >= abn[i]) stm.pop();
        stm.push({i, abn[i]});
    }
    cout << "YES\n";
    cout << ans << "\n";
    for (int i = 1; i < n; i++) {
        bruh[i] += bruh[i - 1];
        ab[i] += bruh[i], abn[i] -= bruh[i];
        cout << ab[i] << " " << au[i] << " " << abn[i] << "\n";
    }
    return 0;
}