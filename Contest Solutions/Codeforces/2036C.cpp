#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, q, x, v, a[200001];
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        int cnt = 0;
        for (int i = 1; i <= s.length(); i++) {
            a[i] = (s[i - 1] == '1' ? 1 : 0);
            if (i > 3 && a[i - 3] && a[i - 2] && !a[i - 1] && !a[i]) ++cnt;
        }
        cin >> q;
        while (q--) {
            cin >> x >> v;
            if (a[x] != v) {
                for (int i = max(x, 4); i < min(x + 4, (int)s.length() + 1); i++) if (a[i - 3] && a[i - 2] && !a[i - 1] && !a[i]) --cnt;
                a[x] = v;
                // cout << cnt << " bruh\n";
                for (int i = max(x, 4); i < min(x + 4, (int)s.length() + 1); i++) if (a[i - 3] && a[i - 2] && !a[i - 1] && !a[i]) ++cnt;
            }
            cout << (cnt ? "YES\n" : "NO\n");
        }
    }
    return 0;
}