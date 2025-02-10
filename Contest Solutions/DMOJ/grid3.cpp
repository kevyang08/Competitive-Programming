#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const ll M = 1e9 + 7, MM = M * M;

ll gcdEx(ll a, ll b, ll *x, ll *y) {
    if (a%b == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1, gcd = gcdEx(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    return gcd;
}
ll modInv(ll a, ll m) {
    ll x, y;
    gcdEx(a, m, &x, &y);
    return (x%m + m * m)%m;
}
ll modDiv(ll a, ll b, ll m) {
    ll c = modInv(b, m);
    return (c * a)%m;
}

int n, a[1005], q, x[1005][1005], tot = 0;
ll dp[1005][2], f[1000005], ans = 1, thing[1005][1005], ways[1005]; // thing[i][j] > 0 if all x_ik >= x_jk
bool vis[1005];
void dfs(int i) {
    if (vis[i]) return;
    vis[i] = true;
    for (int j = 1; j <= q; j++) {
        if (j == i || !thing[i][j]) continue;
        dfs(j);
        for (int k = 0; k < 2; k++) dp[i][k ^ 1] = (dp[i][k ^ 1] + dp[j][k] * thing[i][j])%M;
    }
    for (int k = 0; k < 2; k++) ans = (ans + (((ways[i] * dp[i][k])%M) * (k ? -1 : 1))%M + MM)%M;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    f[0] = 1;
    for (int i = 1; i <= 1000000; i++) f[i] = (f[i - 1] * i)%M;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        --a[i];
        tot += a[i];
        ans = (ans * f[a[i]])%M;
    }
    ans = modDiv(f[tot], ans, M);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int tmp = 0;
        dp[i][1] = 1;
        for (int j = 1; j <= n; j++) {
            cin >> x[i][j];
            --x[i][j];
            tmp += x[i][j];
            dp[i][1] = (dp[i][1] * f[x[i][j]])%M;
        }
        dp[i][1] = modDiv(f[tmp], dp[i][1], M);
    }
    for (int i = 1; i <= q; i++) {
        ways[i] = 1;
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp += a[j] - x[i][j];
            ways[i] = (ways[i] * f[a[j] - x[i][j]])%M;
        }
        ways[i] = modDiv(f[tmp], ways[i], M);
    }
    for (int i = 1; i <= q; i++) {
        for (int j = 1; j <= q; j++) {
            if (j == i) continue;
            thing[i][j] = 1;
            int tmp = 0;
            for (int k = 1; k <= n; k++) {
                if (x[i][k] < x[j][k]) {
                    thing[i][j] = 0;
                    break;
                }
                tmp += x[i][k] - x[j][k];
                thing[i][j] = (thing[i][j] * f[x[i][k] - x[j][k]])%M;
            }
            if (thing[i][j]) thing[i][j] = modDiv(f[tmp], thing[i][j], M);
        }
    }
    for (int i = 1; i <= q; i++) if (!vis[i]) dfs(i);
    cout << ans << "\n";
    return 0;
}