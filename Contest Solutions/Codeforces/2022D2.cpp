#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, a, b, ans;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 2; i <= n; i += 2) {
            cout << "? " << i - 1 << " " << i << endl;
            cin >> a;
            cout << "? " << i << " " << i - 1 << endl;
            cin >> b;
            if (a != b) {
                int tmp = (i == n ? i - 2 : i + 1);
                cout << "? " << tmp << " " << i << endl;
                cin >> a;
                cout << "? " << i << " " << tmp << endl;
                cin >> b;
                if (a != b) ans = i;
                else ans = i - 1;
                break;
            }
        }
        if (!ans) ans = n;
        cout << "! " << ans << endl;
    }
    return 0;
}