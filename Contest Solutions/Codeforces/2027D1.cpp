#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 1e9 + 7;

int t, n, m, b;
ll a[300005], mn[300005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        fill(mn + 1, mn + n + 1, INFL);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int k = 1; k <= m; k++) {
            cin >> b;
            for (int i = 1, j = 0; i <= n; i++) {
                while (j < i && a[i] - a[j] > b) ++j;
                if (j == i) continue;
                mn[i] = min(mn[i], mn[j] + m - k);
            }
        }
        cout << (mn[n] == INFL ? -1 : mn[n]) << "\n";
    }
    return 0;
}