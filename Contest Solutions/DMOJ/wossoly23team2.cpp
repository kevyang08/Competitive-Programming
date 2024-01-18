#include <bits/stdc++.h>
using namespace std;

int n, h[100005], l[100005], r[100005];
long long ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        l[i] = max(h[i], l[i - 1]);
    }
    for (int i = n; i > 0; i--) {
        r[i] = max(h[i], r[i + 1]);
        ans += min(r[i], l[i]) - h[i];
    }
    cout << ans << "\n";
    return 0;
}
