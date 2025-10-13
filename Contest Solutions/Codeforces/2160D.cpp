#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, r;
void solve() {
    cin >> n;
    vector<int> ans(2 * n + 1);
    vector<int> cur, bruh;
    for (int i = 1; i <= 2 * n; i++) {
        cur.push_back(i);
        cout << "? " << cur.size();
        for (int &j : cur) cout << ' ' << j;
        cout << endl;
        cin >> r;
        if (r) {
            ans[i] = r;
            bruh.push_back(i);
            cur.pop_back();
        }
    }
    for (int i = 0; i < n; i++) {
        bruh.push_back(cur.back());
        cur.pop_back();
        cout << "? " << bruh.size();
        for (int &j : bruh) cout << ' ' << j;
        cout << endl;
        cin >> ans[bruh.back()];
        bruh.pop_back();
    }
    cout << '!';
    for (int i = 1; i <= 2 * n; i++) cout << ' ' << ans[i];
    cout << endl;
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