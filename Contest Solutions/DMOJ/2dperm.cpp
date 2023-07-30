#include <bits/stdc++.h>
using namespace std;

int cnt[25000002], n, m, q, x;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt[i * j]++;
            cnt[n * m - (n - i + 1) * (m - j + 1) + 2]--;
        }
    }
    for (int i = 1; i <= 25000000; i++) cnt[i] += cnt[i - 1];
    while (q--) {
        cin >> x;
        cout << cnt[x] << "\n";
    }
    return 0;
}
