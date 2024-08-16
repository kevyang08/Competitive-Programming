#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 1; i < n; i += 2) {
            int temp = min(k, a[i - 1] - a[i]);
            k -= temp;
            a[i] += temp;
            ans -= a[i];
        }
        for (int i = 0; i < n; i += 2) ans += a[i];
        cout << ans << "\n";
    }
    return 0;
}