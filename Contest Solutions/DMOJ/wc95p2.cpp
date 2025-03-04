#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int k, ncr[32][32], ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (int i = 0; i < 32; i++) ncr[i][0] = 1; // pascals formula
    for (int i = 1; i < 32; i++)
        for (int j = 1; j <= i; j++)
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    cin >> k;
    int n = k;
    for (int i = 1; i < 32 - __builtin_clz(k); i++) {
        for (int j = 1; j <= i - j; j++) {
            ans += ncr[i - 1][j - 1];
        }
    }
    if (__builtin_popcount(k) <= 32 - __builtin_clz(k) - __builtin_popcount(k)) ++ans;
    int idx = 31 - __builtin_clz(k), z = 1, o = 0;
    while (__builtin_popcount(k) > 1) {
        k ^= (1 << idx);
        int tmp = 31 - __builtin_clz(k);
        ++o; z += idx - tmp - 1;
        for (int j = 0; j + o <= tmp - j + z; j++) ans += ncr[tmp][j];
        idx = tmp;
    }
    cout << "There are " << ans << " round numbers less than or equal to " << n << ".\n";
    return 0;
}