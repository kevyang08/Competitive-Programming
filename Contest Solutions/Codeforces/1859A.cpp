#include <bits/stdc++.h>
using namespace std;
 
int t, n, a[101], b[101], c[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int idb = 0, idc = 0, mx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
        for (int i = 1; i <= n; i++) {
            if (a[i] != mx) b[++idb] = a[i];
            else c[++idc] = a[i];
        }
        if (idb == 0 || idc == 0) cout << "-1\n";
        else {
            cout << idb << " " << idc << "\n";
            for (int i = 1; i <= idb; i++) cout << (i == 1 ? "" : " ") << b[i];
            cout << "\n";
            for (int i = 1; i <= idc; i++) cout << (i == 1 ? "" : " ") << c[i];
            cout << "\n";
        }
    }
    return 0;
}
