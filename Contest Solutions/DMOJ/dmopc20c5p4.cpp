#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int n, m;
string s;
ll ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    vector<vector<int>> v(max(n, m), vector<int>(min(n, m)));
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (n >= m) for (int j = 0; j < m; j++) v[i][j] = s[j] == 'B';
        else for (int j = 0; j < m; j++) v[j][i] = s[j] == 'B';
    }
    if (n < m) swap(n, m);
    map<ll, int> mp;
    vector<ll> h(n);
    for (int l = 0; l < m - 1; l++) {
        for (int i = 0; i < n; i++) h[i] = v[i][l];
        for (int r = l + 1; r < m; r++) {
            mp.clear();
            for (int i = 0; i < n; i++) {
                h[i] = (h[i] * 2 + v[i][r])%M;
                if (v[i][r] != v[i][l]) {
                    mp.clear();
                    continue;
                }
                ans += mp[h[i]];
                ++mp[h[i]];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}