#include <bits/stdc++.h>
using namespace std;

int t, n, b[100001], a[100001], c[100001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        bool thing = true;
        cin >> n;
        for (int i = 2; i <= n; i++) cin >> b[i];
        a[1] = b[2];
        a[n] = b[n];
        for (int i = 2; i < n; i++) {
            a[i] = (b[i] | b[i + 1]);
            if ((a[i] & a[i - 1]) != b[i]) thing = false;
        }
        if (thing) for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? "\n" : " ");
        else cout << "-1\n";
    }
    return 0;
}