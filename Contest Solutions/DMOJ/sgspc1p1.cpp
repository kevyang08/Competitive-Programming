#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, a, ans = 0;
    cin >> n;
    ll cnt[31], bruh[31], thing = 0;
    for (int i = 0; i < 31; i++) cnt[i] = bruh[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ll c = n - i;
        for (int j = 0; j < 31; j++) {
            if (a & (1 << j)) cnt[j] += c + thing;
            else bruh[j] += c + thing;
        }
        thing += c - i - 1;
    }
    for (int i = 0; i < 31; i++) if (cnt[i] > bruh[i]) ans += (1 << i);
    cout << ans << "\n";
}
