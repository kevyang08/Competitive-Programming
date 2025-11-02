#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int n, v[100005], f[100005], ind[100005], mx[2][100005], flag = -1, cnt = 0;
ll ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> f[i];
        ans += f[i];
        ++ind[v[i]];
        if (f[i] > mx[0][v[i]]) {
            mx[1][v[i]] = mx[0][v[i]];
            mx[0][v[i]] = f[i];
        }
        else if (f[i] > mx[1][v[i]]) mx[1][v[i]] = f[i];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.push(i);
        ans -= mx[0][i];
    }
    if (!q.empty()) flag = 1;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        --ind[v[c]];
        if (!ind[v[c]]) q.push(v[c]);
    }
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) continue;
        ++cnt;
        int c = i, mn = INF;
        while (ind[i]) {
            mn = min(mn, max(f[c] - mx[1][v[c]], 0));
            --ind[v[c]];
            c = v[c];
        }
        flag *= mn;
        ans += mn;
    }
    if (cnt == 1 && flag < 0) ans += flag;
    cout << ans << "\n";
    return 0;
}