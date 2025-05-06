#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n == 2 * k) {
            cout << "! " << k << " " << k << endl;
            continue;
        }
        vector<int> a(k);
        for (int i = 1; i <= k; i++) {
            cout << "? " << i << endl;
            cin >> a[i%k];
        }
        int l = 1, r = n/k, off = n%k;
        while (r * k + off > n - k) {
            cout << "? " << r * k + off << endl;
            cin >> c;
            if (c != a[(off + k)%k]) break;
            --off;
        }
        if (c == a[(off + k)%k]) {
            cout << "! -1" << endl;
            continue;
        }
        if (off > 0) --l;
        while (l < r) {
            int m = (l + r + 1)/2;
            cout << "? " << m * k + off << endl;
            cin >> c;
            if (c == a[(off + k)%k]) l = m;
            else r = m - 1;
        }
        l = l * k + off;
        cout << "? " << l << endl;
        cin >> c;
        while (c == a[l%k] && n - l >= k) {
            cout << "? " << ++l << endl;
            cin >> c;
        }
        --l;
        cout << "? " << l + k << endl;
        cin >> c;
        if (c == a[l%k] && l > k) {
            cout << "! -1" << endl;
            continue;
        }
        cout << "! " << l << " " << n - l << endl;
    }
    return 0;
}