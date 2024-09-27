#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[50005], mn[50005][2], sieve[50005], ans[50005], tmp[50005], idx = 1, mna[2] = {0x3f3f3f3f, 0x3f3f3f3f};
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = tmp[i] = a[i];
    }
    sort(tmp + 1, tmp + 1 + n);
    while (idx < n && a[idx] == tmp[idx]) ++idx;
    if (idx + 1 >= n) {
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) continue;
        for (int j = i + i; j <= n; j += i) sieve[j] = true;
        mn[i][0] = a[idx];
        for (int j = idx + i; j <= n; j += i) mn[i][0] = min(mn[i][0], a[j]);
        mna[0] = min(mna[0], mn[i][0]);
    }
    for (int i = 2; i <= n; i++) {
        if (sieve[i] || mn[i][0] != mna[0]) continue;
        mn[i][1] = a[idx + 1];
        for (int j = idx + i + 1; j <= n; j += i) mn[i][1] = min(mn[i][1], a[j]);
        mna[1] = min(mna[1], mn[i][1]);
    }
    for (int j = 2; j <= n; j++) {
        if (sieve[j] || mn[j][0] != mna[0] || mn[j][0] == mna[0] && mn[j][1] > mna[1]) continue;
        vector<vector<int>> v(j);
        for (int i = idx; i <= n; i++) v[i%j].push_back(a[i]);
        for (int i = 0; i < j; i++) sort(v[i].begin(), v[i].end(), greater<int>());
        for (int i = idx; i <= n; i++) {
            int x = v[i%j].back();
            if (x != ans[i]) {
                if (x < ans[i]) for (int k = i; k <= n; k++) ans[k] = v[k%j].back(), v[k%j].pop_back();
                break;
            }
            v[i%j].pop_back();
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}