#include <bits/stdc++.h>
using namespace std;

int t, n, q, l, r, fa[26][200001], fb[26][200001];
string a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> q >> a >> b;
        for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++) fa[j][i] = fa[j][i - 1] + (a[i - 1] - 'a' == j);
        for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++) fb[j][i] = fb[j][i - 1] + (b[i - 1] - 'a' == j);
        while (q--) {
            cin >> l >> r;
            int res = r - l + 1;
            for (int i = 0; i < 26; i++) res -= min(fa[i][r] - fa[i][l - 1], fb[i][r] - fb[i][l - 1]);
            cout << res << "\n";
        }
    }
    return 0;
}