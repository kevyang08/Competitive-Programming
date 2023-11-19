#include <bits/stdc++.h>
using namespace std;
 
int t, n;
long long a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<double, int> cnt;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += cnt[a[i] - log2l(a[i])];
            cnt[a[i] - log2l(a[i])]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
