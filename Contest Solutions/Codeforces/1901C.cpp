#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[200005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0, mn = 0x3f3f3f3f, mx = 0;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        while (mn < mx) {
            v.push_back(mn);
            mx = (mx + mn)/2;
        }
        cout << v.size() << "\n";
        if (v.size() <= n) for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
    return 0;
}
