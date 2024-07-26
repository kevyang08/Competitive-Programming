#include <bits/stdc++.h>
using namespace std;

/*
- second half: if c[i] >= i, 1 else 0
- first half: calculate time it takes for a[i] = 0
*/

int t, n, c[200001], a[200001], s[200001], e[200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        fill(a, a + n + 1, 1);
        fill(s, s + n + 1, 1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1, j = 1; j <= n; i++) {
            if (!c[i]) {
                e[i] = i, j = i + 1, a[i] = 0;
                continue;
            }
            for (int k = 0; k < c[i] - e[i - 1] + s[i] - 1 && j <= n; k++) ++j;
            if (j <= n) e[i] = j, s[j] = j, a[j++] = 0;
        }
        for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? "\n" : " ");
    }
    return 0;
}