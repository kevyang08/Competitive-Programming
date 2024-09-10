#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int l = 0;
        for (int i = 0; i < n; i++) {
            cin >> b;
            if (b > 0) ++l;
        }
        int dl = n - l;
        for (int i = 1; i <= l; i++) cout << i << " ";
        for (int i = 1; i <= dl; i++) cout << l - i << " ";
        cout << "\n";
        for (int i = 1; i <= n; i++) cout << (i <= dl * 2 ? i%2 : i - dl * 2) << " ";
        cout << "\n";
    }
    return 0;
}