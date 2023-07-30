#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, a, ans = 0;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a;
        unordered_map<int, int> temp;
        for (int j = 0; j < 30; j++) {
            if (a & (1 << j)) {
                for (int k = 0; k < 30; k++) {
                    if (a & (1 << k)) temp[k] = max(temp[k], mp[j] + 1);
                    ans = max(ans, temp[k]);
                }
            }
        }
        for (int j = 0; j < 30; j++) mp[j] = max(mp[j], temp[j]);
    }
    cout << ans << "\n";
    return 0;
}
