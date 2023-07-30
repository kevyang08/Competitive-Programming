#include <bits/stdc++.h>
using namespace std;

int n, MOD = 1000000007;
long long h, ans = 1, temp;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        temp = 1;
        cin >> h;
        while (h%2 == 0) {
            h /= 2;
            temp = temp * temp + 1;
            temp %= MOD;
        }
        ans *= temp;
        ans %= MOD;
    }
    cout << ans << "\n";
}
