#include <bits/stdc++.h>
using namespace std;

int n, b, a[100001], idx, s = 0, g = 0, arr[2][100001], ans = 1;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == b) idx = i;
    }
    for (int i = idx - 1; i > 0; i--) {
        if (a[i] < b) s++;
        else g++;
        if (s == g) ans++;
        arr[(idx - i)%2][s - g + 50000]++;
    }
    s = g = 0;
    for (int i = idx + 1; i <= n; i++) {
        if (a[i] < b) s++;
        else g++;
        if (s == g) ans++;
        ans += arr[(i - idx)%2][g - s + 50000];
    }
    cout << ans << "\n";
}
