#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, a[500001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        int n = s.length(), ans = 0;
        fill(a, a + n + 1, 1);
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == s[i - 2]) a[i] += a[i - 1];
            else ans += a[i - 1]/2;
        }
        ans += a[n]/2;
        int temp = ans, cur = 1, idx = 1, bruh = 0;
        char c = s[0];
        while (idx < n && s[idx - 1] == s[idx]) ++cur, ++idx;
        if (idx == n) {
            cout << n/2 << "\n";
            continue;
        }
        temp -= cur/2;
        for (int i = n; i > 1; i--) {
            if (a[i] > 1) {
                if (i > idx) temp = temp - a[i]/2 + a[i - 1]/2;
                else {
                    temp = temp - (1 - bruh%2);
                    --bruh;
                }
            }
            if (s[i - 1] == c) ++cur;
            else {
                temp += cur/2;
                if (!bruh) bruh = cur;
                c = s[i - 1];
                cur = 1;
            }
            ans = min(ans, temp + cur/2);

            // cout << temp << " " << cur << "what\n";

            // cout << temp + cur/2 << " bruh\n";
        }
        cout << ans << "\n";
    }
    return 0;
}