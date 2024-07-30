#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        bool thing = true;
        vector<int> ans;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1 && a[i]%2 != a[i - 1]%2) thing = false;
        }
        if (!thing) {
            cout << "-1\n";
            continue;
        }
        while (true) {
            int mx = 0;
            for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
            if (!mx) break;
            ans.push_back(mx/2 + mx%2);
            for (int i = 1; i <= n; i++) a[i] = abs(a[i] - ans.back());
        }
        cout << ans.size() << "\n";
        for (auto &i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}