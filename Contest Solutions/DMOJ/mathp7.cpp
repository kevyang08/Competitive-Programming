#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i * i <= n; i++) ans += (n - i * i + i)/i * 2 - 1;
    cout << ans << "\n";
}
