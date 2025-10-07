#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, k;
string s;
void solve() {
    cin >> n >> k >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '0') ++a;
        else if (s[i] == '1') ++b;
        else ++c;
    }
    for (int i = 0; i < n; i++) {
        if (k == n) cout << '-';
        else if (i < a) cout << '-';
        else if (i < a + c) cout << '?';
        else if (i >= n - b) cout << '-';
        else if (i >= n - b - c) cout << '?';
        else cout << '+';
    }
    cout << '\n';
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