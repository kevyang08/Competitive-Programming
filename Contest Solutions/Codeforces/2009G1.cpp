#include <bits/stdc++.h>
using namespace std;

int t, n, k, q, l, r, a[200001], ans[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> q;
        map<int, int> mp;
        multiset<int> ms;
        for (int i = 1, j = 1; i <= n; i++) {
            cin >> a[i];
            if (mp.find(a[i] - i) != mp.end()) ms.extract(mp[a[i] - i]);
            ms.insert(++mp[a[i] - i]);
            if (i - j >= k) {
                ms.extract(mp[a[j] - j]);
                ms.insert(--mp[a[j] - j]);
                ++j;
            }
            ans[i] = k - *ms.rbegin();
        }
        while (q--) {
            cin >> l >> r;
            cout << ans[r] << "\n";
        }
    }
    return 0;
}