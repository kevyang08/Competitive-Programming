#include <bits/stdc++.h>
using namespace std;

int n, m, mn = 0, mx = 0;
string s;
bool used[500001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (n--) {
        cin >> s;
        fill(used, used + m + 1, 0);
        int c = m/4, cnt = 0;
        for (int i = 1; i < m; i++) if (c && s[i - 1] == '1' && s[i] == '1') ++mn, --c, used[i] = 1, used[++i] = 1;
        for (int i = 1; i <= m; i++) {
            if (used[i]) continue;
            if (c && i < m && !used[i + 1]) {
                if (s[i - 1] == '1' || s[i] == '1') ++mn;
                --c, ++i;
            }
            else if (s[i - 1] == '1') ++mn;
        }
        fill(used, used + m + 1, 0);
        c = m/4;
        for (int i = 1; i < m; i++) if (c && (s[i - 1] == '0' || s[i] == '0')) mx += (s[i] == '1' || s[i - 1] == '1'), --c, used[i] = 1, used[++i] = 1;
        for (int i = 1; i <= m; i++) {
            if (used[i]) continue;
            if (c && i < m && !used[i + 1]) {
                if (s[i - 1] == '1' || s[i] == '1') ++mx;
                --c, ++i;
            }
            else if (s[i - 1] == '1') ++mx;
        }
    }
    cout << mn << " " << mx << "\n";
    return 0;
}