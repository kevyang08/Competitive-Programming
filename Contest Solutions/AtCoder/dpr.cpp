#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

const int M = 1e9 + 7;

int n;
ll k, a[51][51], cur[51][51], ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cur[i][i] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    while (k) {
        if (k & 1) {
            vector<vector<ll>> tmp(n + 1, vector<ll>(n + 1));
            for (int i = 1; i <= n; i++) 
                for (int j = 1; j <= n; j++) 
                    for (int k = 1; k <= n; k++) 
                        tmp[i][k] = (tmp[i][k] + cur[i][j] * a[j][k])%M;
            for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cur[i][j] = tmp[i][j];
        }
        vector<vector<ll>> tmp(n + 1, vector<ll>(n + 1));
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                for (int k = 1; k <= n; k++) 
                    tmp[i][k] = (tmp[i][k] + a[i][j] * a[j][k])%M;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = tmp[i][j];
        k >>= 1;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans = (ans + cur[i][j])%M;
    cout << ans << "\n";
    return 0;
}