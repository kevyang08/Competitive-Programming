#include <bits/stdc++.h>
using namespace std;

/*
- arr[r - 1] - arr[l] + (a[l] == '1') + (r != l && a[r] == '1')
- also handle b[l] == '0' and b[r] == '0' accordingly
*/

int t, n, q, l, r, arr[200001];
bool outl[200001], outr[200001];
string a, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        fill(arr, arr + n + 1, 0);
        fill(outl, outl + n + 1, true);
        fill(outr, outr + n + 1, true);
        for (int i = 0; i < n; i++) if (b[i] == '1') outl[i + 1] = outr[i + 1] = false;
        for (int i = 2; i < n; i++) if (a[i] == '0' && a[i - 2] == '0') b[i - 1] = '1';
        arr[1] = a[0] == '1';
        for (int i = 2; i < n; i++) {
            arr[i] = arr[i - 1] + (b[i] == '1' && b[i - 2] == '1' || a[i - 1] == '1');
            if (arr[i] == arr[i - 1] || a[i - 1] == '1') outl[i - 1] = outr[i + 1] = false;
        }
        arr[n] = arr[n - 1] + (a[n - 1] == '1');
        cin >> q;
        while (q--) {
            cin >> l >> r;
            if (r - l < 2) cout << (a[l - 1] == '1') + (r > l && a[r - 1] == '1') << "\n";
            else if (r - l == 2) cout << arr[r - 1] - arr[l] + (a[l - 1] == '1') + (a[r - 1] == '1') - (outl[l] || outr[r]) << "\n";
            else cout << arr[r - 1] - arr[l] + (a[l - 1] == '1') + (a[r - 1] == '1') - outl[l] - outr[r] << "\n";
        }
    }
    return 0;
}