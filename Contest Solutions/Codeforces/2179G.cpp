#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int t, n, dist[2][100005], ans[105][105];
void solve() {
    cin >> n;
    int c1{0}, c2{0};
    for (int i = 2; i <= n * n; i++) {
        cout << "? 1 " << i << endl;
        cin >> dist[0][i];
        if (dist[0][i] > dist[0][c1]) c1 = i;
    }
    vector<int> v;
    for (int i = 1; i <= n * n; i++) {
        if (i == c1) continue;
        cout << "? " << c1 << " " << i << endl;
        cin >> dist[0][i];
        if (dist[0][i] == n - 1) v.push_back(i);
    }
    for (int i = 1; i < n; i++) {
        // cout << v.size() << " herherherehr\n"; // debug
        cout << "? " << v[0] << " " << v[i] << endl;
        cin >> dist[1][v[i]];
        if (dist[1][v[i]] > dist[1][c2]) c2 = v[i];
    }
    dist[1][c2] = 0;
    dist[1][c1] = dist[0][c2];
    ans[1][1] = c1;
    ans[1][n] = c2;
    for (int i = 1; i <= n * n; i++) {
        if (i == c1 || i == c2) continue;
        cout << "? " << c2 << " " << i << endl;
        cin >> dist[1][i];
        int r = (dist[0][i] + dist[1][i] - n + 3)/2, c = dist[0][i] + 2 - r;
        ans[r][c] = i;
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
            if (j == n) cout << endl;
            else cout << ' ';
        }
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