#include <bits/stdc++.h>
using namespace std;

int n, k, a[200001], c[2];
map<int, int> mp[2];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    ++mp[k%2][a[k]];
    ++c[k%2];
    for (int i = 1, j = n, l = k - 1, r = k + 1; i < n - k/2; i++, l--, r++) {
        ans += c[i%2] - mp[i%2][a[i]];
        if (i + 1 < l) ++mp[l%2][a[l]], ++c[l%2];
        if (r <= n) ++mp[r%2][a[r]], ++c[r%2];
        else --mp[j%2][a[j]], --c[j%2], --j;
        if (i > k/2 + 1) --mp[i%2][a[i]], --c[i%2];
    }
    if (k == 1) ans = 0;
    cout << ans << "\n";
    return 0;
}