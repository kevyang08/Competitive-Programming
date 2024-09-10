#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, a[1000005], b, idx = 1;
ll ans[1000005];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b;
        if (idx + b > m) {
            ans[idx] += a[i];
            idx = (idx + b)%m;
            if (!idx) idx = m;
            ans[1] += a[i], ans[idx] -= a[i];
        }
        else {
            ans[idx] += a[i], ans[idx + b] -= a[i];
            idx += b;
        }
    }
    for (int i = 1; i <= m; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << (i == m ? "\n" : " ");
    }
    return 0;
}