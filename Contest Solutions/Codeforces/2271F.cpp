#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, a[200005];
void solve() {
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (a[0] == a[n - 1] && a[0] == mx) {
        cout << "0\n";
        return;
    }
    // if completely covered already anyways, no ops needed
    {
        stack<pair<int, int>> st;
        st.push({0, 1});
        for (int i = 1; i < n; i++) {
            if (st.top().fi == i - 1 && st.top().se > 1) {
                while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
                if (st.empty() || a[i] < a[st.top().fi]) st.push({i, 1});
                else st.top().fi = i, ++st.top().se;
                continue;
            }
            while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
            if (st.empty()) break;
            else if (a[st.top().fi] == a[i]) st.top().fi = i, ++st.top().se;
        }
        if (!st.empty() && n - 1 == st.top().fi && st.top().se > 1) {
            cout << "0\n";
            return;
        }
    }
    // need at least one op
    if (a[0] == mx) cout << "1\n" << n << " " << mx << "\n";
    else if (a[n - 1] == mx) cout << "1\n1 " << mx << "\n";
    else {
        // not completely covered; either prefix or suffix is covered and max is at next index
        int pref = 0, suff = n - 1;
        {
            stack<pair<int, int>> st;
            st.push({0, 1});
            for (int i = 1; i < n; i++) {
                if (st.top().fi == i - 1 && st.top().se > 1) {
                    while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
                    if (st.empty() || a[i] < a[st.top().fi]) {
                        st.push({i, 1});
                        if (a[i] == mx) break;
                    }
                    else st.top().fi = i, ++st.top().se, pref = i;
                    continue;
                }
                while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
                if (st.empty()) break;
                else if (a[st.top().fi] == a[i]) st.top().fi = i, ++st.top().se, pref = i;
            }
            if (!st.empty() && a[st.top().fi] == mx) {
                cout << "1\n" << n << " " << mx << "\n";
                return;
            }
        }
        {
            stack<pair<int, int>> st;
            st.push({n - 1, 1});
            for (int i = n - 2; i >= 0; i--) {
                if (st.top().fi == i + 1 && st.top().se > 1) {
                    while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
                    if (st.empty() || a[i] < a[st.top().fi]) {
                        st.push({i, 1});
                        if (a[i] == mx) break;
                    }
                    else st.top().fi = i, ++st.top().se, suff = i;
                    continue;
                }
                while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
                if (st.empty()) break;
                else if (a[st.top().fi] == a[i]) st.top().fi = i, ++st.top().se, suff = i;
            }
            if (!st.empty() && a[st.top().fi] == mx) {
                cout << "1\n" << "1 " << mx << "\n";
                return;
            }
        }
        // remove max and see if fully covered
        {
            int idx = -1;
            for (int i = pref + 1; i < suff; i++) {
                if (a[i] < mx) continue;
                if (idx != -1) {
                    idx = INF;
                    break;
                }
                idx = i;
            }
            // idx should not be -1, else it would be covered
            if (idx != INF) {
                a[idx] = 1;
                stack<pair<int, int>> st;
                st.push({0, 1});
                for (int i = 1; i < n; i++) {
                    if (st.top().fi == i - 1 && st.top().se > 1) {
                        while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
                        if (st.empty() || a[i] < a[st.top().fi]) st.push({i, 1});
                        else st.top().fi = i, ++st.top().se;
                        continue;
                    }
                    while (!st.empty() && a[i] > a[st.top().fi]) st.pop();
                    if (st.empty()) break;
                    else if (a[st.top().fi] == a[i]) st.top().fi = i, ++st.top().se;
                }
                if (!st.empty() && n - 1 == st.top().fi && st.top().se > 1) {
                    cout << "1\n" << idx + 1 << " 1" << "\n";
                    return;
                }
            }
        }
        // otherwise have to use two ops anyway
        cout << "2\n1 1000000000\n" << n << " 1000000000\n";
    }
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

/*

stuff:
[a..a]mx..mx[b..b]
[a..a]mx...
...mx[b..b]
a..a..mx..[b..b]
[a..a]..mx..b..b
*/